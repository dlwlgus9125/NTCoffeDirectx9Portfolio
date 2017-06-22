#pragma once
#include "IEntity.h"

class cUnit;
// �����ൿ�� ó���ϴ� Ŭ����
class SteeringBehavior
{
	IEntity* m_pEntity;
	// ��ȸ ����

public:
	SteeringBehavior(IEntity* pEntity);

	IEntity* Entity();

	//m_force += force;


	// ���� : ��ǥ������ �����ϴ� �������� �ջ�
	void Arrive(D3DXVECTOR3 targetPos);

	// ���� : �δ밡 ��ǥ������ 
	void LeaderArrive(D3DXVECTOR3 targetPos);

	// ���� : �⺴�δ밡 ��ǥ������ 
	void CavalryLeaderArrive(D3DXVECTOR3 targetPos, float velocity);

	// ���� : ������ ��ǥ������ 
	void UnitArrive(D3DXVECTOR3 targetPos);

	// ���� : �⺴������ ��ǥ������ 
	void CavalryUnitArrive(D3DXVECTOR3 targetPos, float velocity);
	// �߰�
	void Pursuit(IEntity* pTarget);

	// ����
	void Evade(IEntity* pTarget);

	void Wander(D3DXVECTOR3 PosOrigin, float distance);

	void Wander(IEntity * pEntity);

	// ��ȸ
	void Wander(float distance, float radius, float jitter);

	void AvoidObstacle(ST_SPHERE pObstacle);


	// ��ֹ� ȸ��
	void AvoidObstacle(IEntity* pObstacle);

	// ��ֹ� ȸ�� (����)
	void AvoidObstacle(vector<cUnit*> obstacles);

	// ��ħ ����
	void ConstrainOverlap(IEntity* pTarget);

	// ��ħ ����
	void ConstrainOverlap(vector<IEntity*> targets);

	void OffsetPursuit(IEntity* pLeader, D3DXVECTOR3 offset);

	void CavalryOffsetPursuit(IEntity* pLeader, D3DXVECTOR3 offset);

	// �� �̵�
	/*void FollowPath(Grid& grid, vector<int>& path, float seekDistance)
	{
	if (path.size() == 0) return;

	Vector targetPos = grid.TilePos(path.back());

	if (path.size() > 1)
	{
	Seek(targetPos);

	if (MATH->SqrDistance(Entity()->Pos(), targetPos) < seekDistance * seekDistance)
	{
	path.pop_back();
	}
	}
	else
	{
	Arrive(targetPos);

	if (MATH->SqrDistance(Entity()->Pos(), targetPos) < 20)
	{
	path.pop_back();
	m_force = Vector(0, 0);
	Entity()->SetVelocity(Vector(0, 0));
	}
	}
	}*/
};