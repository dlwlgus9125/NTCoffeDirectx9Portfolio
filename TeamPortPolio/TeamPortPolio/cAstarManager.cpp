#include "stdafx.h"
#include "cAstarManager.h"
#include "cRay.h"
#include "cObject.h"
#include "cPlayer.h"
#include "cLeader.h"
#include "cUnit.h"




void cAstarManager::Init()
{
	m_PathGraph = m_graph = NULL;
}

void cAstarManager::Setup(vector<D3DXVECTOR3> vecPosOfNode)
{
	m_vecPosOfNode = vecPosOfNode;

	m_graph = new cGraph(m_vecPosOfNode.size());
	int col = sqrt(m_vecPosOfNode.size());
	for (int i = 0; i < m_vecPosOfNode.size(); i++)
	{
		m_graph->GetNode(i)->SetActive(false);

		D3DXVECTOR3 pos;//<-食奄拭 heightmap尻至背辞 疎妊隔奄
		//益係惟馬檎 株戚葵猿走 坪什闘稽 旋遂戚 亜管馬奄凶庚拭 神備形 切尻什君崇

		m_graph->GetNode(i)->SetPos(m_vecPosOfNode[i]);
		int index = 0;
		MAP->GetMap()->GetIndex(m_vecPosOfNode[i].x, m_vecPosOfNode[i].z, index);
		m_graph->GetNode(i)->SetID(index);
	}
	for (int i = 0; i < m_vecPosOfNode.size(); i++)
	{
		if (m_vecPosOfNode[i].y == 0.0f || m_vecPosOfNode[i].y == 1.0f || m_vecPosOfNode[i].y == 2.0f || m_vecPosOfNode[i].y == 3.0f || m_vecPosOfNode[i].y == 4.0f)
		{
			m_graph->GetNode(i)->SetActive(true);
		}
	}
	for (int i = 0; i < m_vecPosOfNode.size(); i++)
	{
		int x = i % col;	// 伸 腰硲
		int z = i / col;	// 匝 腰硲	

		AddEdge(i, x - 1, z + 0);//背雁 色走研 幻級凶 株戚拭魚虞辞 色走蓄亜食採 尻至
		AddEdge(i, x + 1, z + 0);
		AddEdge(i, x + 0, z - 1);//色走澗 析舘 葛球 匂走芝聖 穿採 限秩板
		AddEdge(i, x + 0, z + 1);
		AddEdge(i, x - 1, z - 1);
		AddEdge(i, x - 1, z + 1);
		AddEdge(i, x + 1, z - 1);
		AddEdge(i, x + 1, z + 1);
	}
	SetupGraph();
	THREAD->CreateFindIndexThread(HANDLE_ASTAR_FINDINDEX);
	//THREAD->CreateFindPathThread(HANDLE_ATSTAR_FINDPATH);
}

void cAstarManager::DestroyForChangeScene()
{
	THREAD->TerminateThreadByKey(HANDLE_ASTAR_FINDINDEX);
	THREAD->TerminateThreadByKey(HANDLE_ATSTAR_FINDPATH);
	//
}

void cAstarManager::SetupGraph()
{
	m_PathGraph = new cGraph(m_vecPosOfNode.size());
	int col = sqrt(m_vecPosOfNode.size());
	for (int i = 0; i < m_vecPosOfNode.size(); i++)
	{
		m_PathGraph->GetNode(i)->SetActive(false);

		D3DXVECTOR3 pos;//<-食奄拭 heightmap尻至背辞 疎妊隔奄
						//益係惟馬檎 株戚葵猿走 坪什闘稽 旋遂戚 亜管馬奄凶庚拭 神備形 切尻什君崇

		m_PathGraph->GetNode(i)->SetPos(m_vecPosOfNode[i]);
		int index = 0;
		MAP->GetMap()->GetIndex(m_vecPosOfNode[i].x, m_vecPosOfNode[i].z, index);
		m_PathGraph->GetNode(i)->SetID(index);
	}
	for (int i = 0; i < m_vecPosOfNode.size(); i++)
	{
		if (m_vecPosOfNode[i].y == 0.0f || m_vecPosOfNode[i].y == 1.0f || m_vecPosOfNode[i].y == 2.0f || m_vecPosOfNode[i].y == 3.0f || m_vecPosOfNode[i].y == 4.0f)
		{
			m_PathGraph->GetNode(i)->SetActive(true);
		}
	}
	for (int i = 0; i < m_vecPosOfNode.size(); i++)
	{
		int x = i % col;	// 伸 腰硲
		int z = i / col;	// 匝 腰硲	

		AddEdgeInPathGraph(i, x - 1, z + 0);//背雁 色走研 幻級凶 株戚拭魚虞辞 色走蓄亜食採 尻至
		AddEdgeInPathGraph(i, x + 1, z + 0);
		AddEdgeInPathGraph(i, x + 0, z - 1);//色走澗 析舘 葛球 匂走芝聖 穿採 限秩板
		AddEdgeInPathGraph(i, x + 0, z + 1);
		AddEdgeInPathGraph(i, x - 1, z - 1);
		AddEdgeInPathGraph(i, x - 1, z + 1);
		AddEdgeInPathGraph(i, x + 1, z - 1);
		AddEdgeInPathGraph(i, x + 1, z + 1);
	}
}

void cAstarManager::AddEdge(int from, int col, int row)
{
	if (col >= 0 && col < sqrt(m_vecPosOfNode.size()) && row >= 0 && row < sqrt(m_vecPosOfNode.size()))
	{
		int to = col + row *  sqrt(m_vecPosOfNode.size());
		D3DXVECTOR3 fromPos = m_graph->GetNode(from)->Pos();//get葛球稽 坦軒背辞 色走蓄亜食採 衣舛馬奄
		D3DXVECTOR3 toPos = m_graph->GetNode(to)->Pos();

		if (abs(fromPos.y - toPos.y) <= 1.0f&&m_graph->GetNode(from)->Active() == true && m_graph->GetNode(to)->Active() == true)
		{
			D3DXVECTOR3 length = toPos - fromPos;

			m_graph->AddEdge(from, to, sqrt(pow(length.x, 2) + pow(length.z, 2)));
		}
	}
}

void cAstarManager::AddEdgeInPathGraph(int from, int col, int row)
{
	if (col >= 0 && col < sqrt(m_vecPosOfNode.size()) && row >= 0 && row < sqrt(m_vecPosOfNode.size()))
	{
		int to = col + row *  sqrt(m_vecPosOfNode.size());
		D3DXVECTOR3 fromPos = m_graph->GetNode(from)->Pos();//get葛球稽 坦軒背辞 色走蓄亜食採 衣舛馬奄
		D3DXVECTOR3 toPos = m_graph->GetNode(to)->Pos();

		if (abs(fromPos.y - toPos.y) <= 1.0f&&m_graph->GetNode(from)->Active() == true && m_graph->GetNode(to)->Active() == true)
		{
			D3DXVECTOR3 length = toPos - fromPos;

			m_PathGraph->AddEdge(from, to, sqrt(pow(length.x, 2) + pow(length.z, 2)));
		}
	}
}


vector<int> cAstarManager::GetPath(int chrindex, int targetIndex)
{
	if (chrindex != targetIndex)
	{
		/*	cGraph* pGraph = SetupGraph();*/
		cAstar as(m_PathGraph, chrindex, targetIndex);
		if (as.Search())
		{
			return as.GetPath();
		}
		/*SAFE_DELETE(pGraph);*/
	}
	return vector<int>();
}

void cAstarManager::Update()
{
	if (TIME->UpdateOneSecond())
	{
		SetObjectIndex();
		SetTargetOfLeader();
		//cout << "player index : " <<OBJECT->GetPlayer()->GetIndex()<< endl;
	}
}

void cAstarManager::PathUpdate()
{
	SetLeaderPath();
	THREAD->SuspendThreadByKey(HANDLE_ATSTAR_FINDPATH);
}

void cAstarManager::Release()
{
	THREAD->TerminateThreadByKey(HANDLE_ASTAR_FINDINDEX);
	THREAD->TerminateThreadByKey(HANDLE_ATSTAR_FINDPATH);
	m_isMapLoadingComplete = false;
	if (m_PathGraph)SAFE_DELETE(m_PathGraph);
	m_PathGraph = NULL;
	if (m_graph)SAFE_DELETE(m_graph);
	m_graph = NULL;
	m_vecPosOfNode.clear();
}

void cAstarManager::Render()
{
	if (m_graph)m_graph->Render();
}

bool cAstarManager::GetCursorIndex(int & TargetIndex)
{
	if (m_graph)
	{
		int cellIndex = -1;	// 五習 中宜 蒸生檎 昔畿什澗 -1. 焼艦虞檎 背雁 昔畿什 蟹臣 依績.

		D3DXVECTOR3 posOnMap = D3DXVECTOR3(-1000, -1000, -1000);	//	床傾奄葵 隔嬢砧奄. 己 骨是 鎧 啄走 省紹生檎 戚 床傾奄葵 益企稽 蟹身.

		float minX = MAP->GetMinX();	// IsCollidedWithMesh税 森須坦軒研 是廃 痕呪
		float maxX = MAP->GetMaxX();	// IsCollidedWithMesh税 森須坦軒研 是廃 痕呪

		cRay::IsCollidedWithMesh(INPUT->GetMousePosVector2(), MAP->GetMesh(), cellIndex, posOnMap, minX, maxX);
		//cout << "posOnMap.x : " << posOnMap.x << "posOnMap.z : " << posOnMap.z<< endl;
		if (cellIndex != -1 && m_graph->GetNode(cellIndex)->Active() != false) { cout << "Active !! cellindex : " << cellIndex << endl; TargetIndex = cellIndex; return true; }
		else { cout << "Non-Active !!" << endl; return false; }

	}
	return false;
}

void cAstarManager::SetObjectIndex()
{
	for (int i = 0; i < OBJECT->GetLeader().size(); i++)
	{
		D3DXVECTOR3 pos = OBJECT->GetLeader()[i]->GetCharacterEntity()->Pos();
		int index = 0;
		MAP->GetMap()->GetIndex(pos.x, pos.z, index);
		if (OBJECT->GetLeader()[i]->GetIndex() != index)OBJECT->GetLeader()[i]->SetIndex(index);
	}
	D3DXVECTOR3 pos = OBJECT->GetPlayer()->GetCharacterEntity()->Pos();
	int index = 0;
	MAP->GetMap()->GetIndex(pos.x, pos.z, index);
	if (OBJECT->GetPlayer()->GetIndex() != index)OBJECT->GetPlayer()->SetIndex(index);
}

void cAstarManager::SetLeaderPath()
{
	for (int i = 0; i < OBJECT->GetLeader().size(); i++)
	{
		if (OBJECT->GetLeader()[i]->GetPath().size() <= 0 && OBJECT->GetLeader()[i]->GetIndex() != OBJECT->GetLeader()[i]->GetTargetIndex())
		{
			OBJECT->GetLeader()[i]->PathClear();
			OBJECT->GetLeader()[i]->SetPath(this->GetPath(OBJECT->GetLeader()[i]->GetIndex(), OBJECT->GetLeader()[i]->GetTargetIndex()));
		//	cout << "path size : " << OBJECT->GetLeader()[i]->GetPath().size() << endl;
		}
	}
}

void cAstarManager::SetLeaderPath(cLeader* pLeader)
{


}

//...せせせせせせせ
void cAstarManager::SetTargetOfLeader()
{
	for (int thisLeader = 0; thisLeader < OBJECT->GetLeader().size(); thisLeader++)
	{
		if (OBJECT->GetLeader()[thisLeader]->IsDeath() == false)
		{
			for (int anotherLeader = 0; anotherLeader < OBJECT->GetLeader().size(); anotherLeader++)
			{
				if (OBJECT->GetLeader()[anotherLeader]->IsDeath() == false)
				{
					if (OBJECT->GetLeader()[thisLeader]->GetCamp() != OBJECT->GetLeader()[anotherLeader]->GetCamp())
					{
						if (MATH->IsCollided(OBJECT->GetLeader()[thisLeader]->GetArrangeSphere(), OBJECT->GetLeader()[anotherLeader]->GetArrangeSphere()))
						{
							if (OBJECT->GetLeader()[thisLeader]->GetTargetObject() != OBJECT->GetLeader()[anotherLeader])
							{
								OBJECT->GetLeader()[thisLeader]->SetTargetObject(OBJECT->GetLeader()[anotherLeader]);
								break;
							}
						}

					}
				}
			}
		}
	}
}
