#pragma once
#include "cCharacter.h"
#include "cUnit.h"
#include "cFrustum.h"
#include "Player_State.h"

enum PLAYER_STATE
{
	PLAYER_STATE_IDLE,
	PLAYER_STATE_WALK,
	PLAYER_STATE_ATTACK,
	PLAYER_STATE_BOWATTACK,
	PLAYER_STATE_DEFENCE,
	PLAYER_STATE_DEFEAT,
};

enum CURRENT_ATTACKTYPE
{
	ATTACK_MELEE,
	ATTACK_BOW,
};

class cLeader;
class Player_State;
class cSkinnedMesh;
class cBallisticArrow;





class cPlayer :
	public cCharacter
{
private:
	cLeader*       m_currentLeader;//�δ��̵��� ����� �������

	//�� ������ ���� ��
	map<int, cLeader*> m_mapLeader;
	LEADER_TYPE m_currentLeaderType;

	cSkinnedMesh*  m_SkinnedMesh;
	float          m_fRotY;
	cStateMachine<cPlayer*>* m_pFsm;


	cSkinnedMesh* m_RightWeaponMesh;
	cSkinnedMesh* m_LeftWeaponMesh;
	

	// >> �ɸ��� ������ ����
	SYNTHESIZE(vector<int>, m_vecInventory, Inventory);	// �κ��丮(����)
	SYNTHESIZE(vector<int>, m_vecEquipment, Equipment); // ���� ������
	// << 

	//>>���⸦ ������ ���� ��ǥ�� �ҷ��������� �ּҰ� �׸�
	ST_BONE* m_rightHand;
	ST_BONE* m_leftHand;
	ST_BONE* m_AttackCollider;

	CURRENT_ATTACKTYPE m_AttackType;

	bool m_isPull;

	ST_SPHERE m_MeleeCollider;

public:
	cPlayer(D3DXVECTOR3 pos, float radius, D3DXVECTOR3 forward, float mass, float maxSpeed);
	~cPlayer();

	void Init();
	void Update(float deltaTime);
	void Render();
	
	void SetRotY(float rotY) { m_fRotY = rotY; }
	float GetRotY() { return m_fRotY; }
	//Scene���� �δ� �̵��� ������ ���Լ�
	cLeader*       GetUnitLeader() { return m_currentLeader; }
	void           SetCurrentLeader(LEADER_TYPE leaderTYPE) { m_currentLeaderType = leaderTYPE; m_currentLeader = m_mapLeader[(int)m_currentLeaderType]; }
	void           SetCurrentLeader() { m_currentLeader = m_mapLeader[(int)m_currentLeaderType]; }

	// �߰�
	cStateMachine<cPlayer*>* FSM() { return m_pFsm; }
	void SetUnitLeaderTargetIndex(int index);

	// >> �κ��丮�� �Լ�
	void SellItem(int itemSID);
	void BuyItem(int itemSID);
	void PutOnItem(int itemSID);
	void PutOffItem(int itemSID);
	// <<

	void Equip();
	void UnEquip();

	//>>Ȱ���� ���
	void IsPullBow(bool pull) { m_isPull = pull; }
	cSkinnedMesh* GetBowSkin() { return m_LeftWeaponMesh; }
	// <<

	//>>Į ������ �浹ü
	ST_SPHERE GetMeleeCollider() { return m_MeleeCollider; }

	D3DXVECTOR3 SetUpAim() {
		D3DXVECTOR3 vAim = CAMERA->GetLookAt() - CAMERA->GetEye();
	
		return	MATH->Nomalize(vAim);
	}

	CURRENT_ATTACKTYPE GetAttackType() { return m_AttackType; }
	void SetAttackColliderPos();

	bool AddUnitInTown(C_C_ID ID);



	void SetAnimBlock() { m_pSkinnedMesh->SetAnimationIndexBlend(P_SHEILDBLOCK); };
	void SetAnimHit() { m_pSkinnedMesh->SetAnimationIndexBlend(P_HIT); };
	void SetAnimDeath() { m_pFsm->Play(PLAYER_STATE_DEFEAT); };
	
	virtual void SetSceneEnter()
	{
		cCharacter::SetSceneEnter();
		m_pFsm->Play(PLAYER_STATE_IDLE);
		SetMode(IDLE_PLAYER_MODE);
	}
};

