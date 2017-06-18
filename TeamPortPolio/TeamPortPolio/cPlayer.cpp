#include "stdafx.h"
#include "cPlayer.h"
#include "cGameManager.h"
#include "cLeader.h"
#include"cArrowMaker.h"


cPlayer::cPlayer(D3DXVECTOR3 pos, float radius, D3DXVECTOR3 forward, float mass, float maxSpeed) 

{
	m_CharacterEntity = new ISteeringEntity(pos, radius, forward, mass, maxSpeed);
	//m_unitLeader = NULL;
	//m_unitLeader = new cLeader(pos, radius, forward, mass, maxSpeed);
	//
	//m_unitLeader->SetID(C_C_HUMAN_CAVALRY);
	//
	//m_unitLeader->SetCamp(CAMP_PLAYER);
	//m_unitLeader->Init();
	//m_unitLeader->SetTargetIndex(ASTAR->GetGraph()->GetNode(16001)->Id());
	//OBJECT->AddObject(m_unitLeader);
	//OBJECT->AddLeader(m_unitLeader);
	m_fRotY = 0.0f;
	m_isAiming = false;
}


cPlayer::~cPlayer()
{
	SAFE_DELETE(m_pFsm);
}

void cPlayer::Init()
{
	m_CollideSphere.fRadius = m_CharacterEntity->Radius();
	m_CollideSphere.vCenter = m_CharacterEntity->Pos();

	m_arrangeCollideSphere.fRadius = 20.0f;
	m_arrangeCollideSphere.vCenter = m_CharacterEntity->Pos();
	cCharacter::Init();


	m_pSkinnedMesh->FindAttackBone(m_Status->m_szColliderBoneName);
	m_pFsm = new cStateMachine<cPlayer*>(this);
	m_pFsm->Register(PLAYER_STATE_IDLE, new Player_Idle());
	m_pFsm->Register(PLAYER_STATE_WALK, new Player_Walk());
	m_pFsm->Register(PLAYER_STATE_ATTACK, new Player_Attack());
	m_pFsm->Register(PLAYER_STATE_DEFENCE, new Player_Defence());
	m_pFsm->Play(PLAYER_STATE_IDLE);

}

void cPlayer::Update(float deltaTime)
{
	cCharacter::Update(deltaTime);
	m_CollideSphere.vCenter.y += 0.5f; // �浹�� ���̰� ����
	m_pFsm->Update(deltaTime);

	D3DXVECTOR3 movePos = m_CharacterEntity->Pos();
	MAP->GetHeight(movePos.x, movePos.y, movePos.z);
	m_CharacterEntity->SetPos(movePos);

	if (INPUT->IsKeyPress(VK_A))
	{
		m_fRotY -= 0.03;
	}
	if (INPUT->IsKeyPress(VK_D))
	{
		m_fRotY += 0.03;
	}


	//<< ȭ��ó��
	if (INPUT->IsMouseDown(MOUSE_RIGHT)&& !m_isAiming)
	{
		
	//	CAMERA->SetCameraDistance(0.1);
		//ȭ�챸ü
		
	}
	
	if (INPUT->IsMouseDown(MOUSE_LEFT)&&!m_isAiming)
	{
		//CAMERA->SetCameraDistance(5);
	
		OBJECT->AddPlayerArrow(m_CharacterEntity, SetUpAim());
		//m_isAiming = true;
	}
	//ȭ��ó��
	
	D3DXMATRIXA16 matR;
	D3DXVECTOR3 forward = D3DXVECTOR3(0, 0, 1);
	D3DXMatrixIdentity(&matR);
	D3DXMatrixRotationY(&matR, m_fRotY);

	D3DXVec3TransformCoord(&forward, &forward, &matR);
	m_CharacterEntity->SetForward(forward);

	m_pSkinnedMesh->SetPosition(m_CharacterEntity->Pos(), m_CharacterEntity->Forward());
	
	CAMERA->SetLookAt(m_CharacterEntity->Pos(), m_fRotY);


}

void cPlayer::Render()
{
	cCharacter::Render();
	//m_unitLeader->Render();

//			//test
//	if (m_pBalisticArrow)
//	{
//		D3DXMATRIXA16 matT, matR, matWorld;
//		D3DXMatrixIdentity(&matT);
//		D3DXMatrixIdentity(&matR);
//		D3DXMatrixTranslation(&matT, m_pBalisticArrow->GetSphere().vCenter.x, m_pBalisticArrow->GetSphere().vCenter.y, m_pBalisticArrow->GetSphere().vCenter.z);
//
//		D3DXVec3TransformCoord(&m_pBalisticArrow->Shoot()->Entity()->Forward(), &m_pBalisticArrow->Shoot()->Entity()->Forward(), &matR);
//		matWorld = matR*matT;
//
//		D3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
//		D3DDevice->SetMaterial(&m_stMtlSphere);
//		D3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
//		m_pMeshSphere->DrawSubset(0);
//		D3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
//	}
}




void cPlayer::SetUnitLeaderTargetIndex(int index)
{
	if (m_unitLeader)
	{
		m_unitLeader->PathClear();
		if (ASTAR->GetGraph()->GetNode(index)->Active())
		{
			m_unitLeader->SetTargetIndex(index);
			/*cout << "targetInd : " << index << endl;
			cout << "size : " << m_unitLeader->GetPath().size() << endl;*/
		}
	}
}

void cPlayer::SellItem(int itemSID)
{
	for (vector<int>::iterator it = m_vecInventory.begin(); it != m_vecInventory.end(); )
	{
		if (*it == itemSID)
		{
			it = m_vecInventory.erase(it);
			break;
		}
		else it++;
	}

	// ����� �۵��ϸ� �������� Math�� ����ϱ�.
}

void cPlayer::ByuItem(int itemSID)
{
	m_vecInventory.push_back(itemSID);

	// ����� �۵��ϸ� �������� Math�� ����ϱ�.
}
