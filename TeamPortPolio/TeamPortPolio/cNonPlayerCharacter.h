#pragma once
#include "cObject.h"
#include "cSkinnedMesh.h"

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

class cNonPlayerCharacter  : public cObject
{
private:
	
protected:
	D3DXVECTOR3                          m_vPosition;
	float                                m_speed;
	float                                m_fRotY;

	//���õǾ��� �ȵǾ���.
	bool                                 m_isPicked;

	//NPC ����
	NPC_KINDS                            m_kind;

	//����ó��
	NPC_STATE                            m_state;

	//�浹ó�� ��ü
	ST_SPHERE                            m_pSphere;

	//�̵� ��� 
	std::vector<D3DXVECTOR3>             m_path;

	cSkinnedMesh*                        m_pSkinnedMesh;

public:
	cNonPlayerCharacter(D3DXVECTOR3 pos, float moveSpeed, float rot, NPC_KINDS kind);
	~cNonPlayerCharacter();

	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render();

	void MovePosition(D3DXVECTOR3 pos, float speed);
	void SetPath(D3DXVECTOR3 pos);
	void AutoMoveAI(vector<D3DXVECTOR3> path);

	NPC_STATE State() { return m_state; }
	D3DXVECTOR3 Postiion() { return m_vPosition; }
	ST_SPHERE Sphere() { return m_pSphere; }
	vector<D3DXVECTOR3> Path() { return m_path; }

	//Manager 
	//void ChangeNpc(int Scene_Tag) { tag = Scene_tag;}
	// SAFE_RELEASE(vector<NPC>) ���ְ�
	// ���� ����
	// tag ������ Setup�� �� �ٸ��� �����ش�.

};

