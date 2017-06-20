#pragma once
#include "cObject.h"

class cSkinnedMesh;


//����
enum NPC_STATE
{
	NPC_NONE,
	NPC_IDLE,
	NPC_WALK,
};

//NPC����
enum NPC_KINDS
{
	NPC_NONE,
	NPC_STORE, //����
	NPC_CITIZEN, // �ɾ�ٴϴ³�
};

class cNonPlayerCharacter  : public cCharacter
{
private:
	
protected:
	float                               m_fRotY;
	cSkinnedMesh*                       m_SkinnedMesh;
	cStateMachine<cNonPlayerCharacter*> m_pFsm;

public:
	cNonPlayerCharacter(D3DXVECTOR3 pos, float radius, D3DXVECTOR3 forward);
	~cNonPlayerCharacter();

	void Init();
	void Update(float deltaTime);
	void Render();

	cStateMachine<cNonPlayerCharacter*> FSM() { return m_pFsm; }
};

