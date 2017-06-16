#pragma once
#include "cUnit.h"
#include "Bow_State.h"

class cBowUnit :
	public cUnit
{
protected:


	cStateMachine<cBowUnit*>* m_pFsm;

	//�ڽ��� �ܴ����ִ� �ִ� ���� ���� �ľ�
public:
	cBowUnit(IEntity* pLeader, D3DXVECTOR3 offset);
	~cBowUnit();

	void Init();
	void Update(float deltaTime);
	void Render();

	cStateMachine<cBowUnit*>* FSM() { return m_pFsm; };

	void SetAnimBlock() { m_pSkinnedMesh->SetAnimationIndexBlend(B_BOWSHEILD); };
	void SetAnimHit() { m_pSkinnedMesh->SetAnimationIndexBlend(B_HIT); };

	void SetAnimDeath() { m_pFsm->Play(UNIT_STATE_BOW_DEATH); };
	void SetBattleState() { m_pFsm->Play(UNIT_STATE_BOW_BATTLE); };
	void SetIdleState() { m_pFsm->Play(UNIT_STATE_BOW_IDLE); };
	void SetDefenceState() { m_pFsm->Play(UNIT_STATE_BOW_DEFENCE); };
};

