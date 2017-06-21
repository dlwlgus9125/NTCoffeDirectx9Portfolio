#include "stdafx.h"
#include "cMapManager.h"
#include "cShadowManager.h"

cMapManager::cMapManager()
{
}


cMapManager::~cMapManager()
{
}

void cMapManager::Init(int sceneID)
{
	char* folderPath = NULL;
	char* filePath = NULL;
	int nCellPerRow = 0;
	float fCellSpace = 0.0f;

	m_pSkyBox = new cSkyBox();
	switch (sceneID)
	{
	case SCENE_TITLE:
		folderPath = "map";
		filePath = strdup("TESTMAP3.txt");
		m_pSkyBox->Setup(nCellPerRow / 2, nCellPerRow / 2, nCellPerRow / 2, "map/SkyBox1", "bmp");
		break;

	case SCENE_TOWN:
		folderPath = "map";
		filePath = strdup("TESTTOWN.txt");
		m_pSkyBox->Setup(nCellPerRow / 2, nCellPerRow / 2, nCellPerRow / 2, "map/SkyBox1", "bmp");
		break;

	case SCENE_BATTLE_HUMAN:
		folderPath = "map";
		filePath = strdup("BATTLE.txt");
		m_pSkyBox->Setup(nCellPerRow / 2, nCellPerRow / 2, nCellPerRow / 2, "map/SkyBox2", "png");
		break;

	case SCENE_BATTLE_ORC:
		folderPath = "map";
		filePath = strdup("BATTLE2.txt");
		m_pSkyBox->Setup(nCellPerRow / 2, nCellPerRow / 2, nCellPerRow / 2, "map/SkyBox3", "png");
		break;
	}

	m_pMap = new cHeightMap();
	cObjLoader loader;
	vector<cMtlTex*> vecMtlTex;
	vector<ST_PNT_VERTEX> vecVertex;
	vector<DWORD> vecIndex;
	LPD3DXMESH pMesh = loader.LoadMesh_Map(vecMtlTex, vecVertex, vecIndex, nCellPerRow, fCellSpace, m_vecConstruct, folderPath, filePath, false);
	m_pMap->Setup(nCellPerRow, fCellSpace, vecVertex, vecIndex);
	m_pMap->SetMesh(pMesh);
	m_pMap->SetVecMtlTex(vecMtlTex);
	// << 

	// >> : ������ ��ǥ �־��� -> ��� �׸���
	m_vPositionVertex = vecVertex[0];

	for (int i = 0; i < vecVertex.size(); i++)
	{
		m_vConstructVertex.push_back(vecVertex[i].p);
	}
	// << :

	// >> ��忡 �� ��� ������ ��ġ ����� �κ�
	
	for (int i = 0; i < vecIndex.size(); i += 6)
	{
		D3DXVECTOR3 v0 = vecVertex[vecIndex[i + 0]].p;
		D3DXVECTOR3 v1 = vecVertex[vecIndex[i + 1]].p;
		D3DXVECTOR3 v2 = vecVertex[vecIndex[i + 2]].p;
		D3DXVECTOR3 v5 = vecVertex[vecIndex[i + 5]].p;

		D3DXVECTOR3 pos;
		pos.x = (v0.x + v1.x + v2.x + v5.x) / 4;
		pos.y = (v0.y + v1.y + v2.y + v5.y) / 4;
		pos.z = (v0.z + v1.z + v2.z + v5.z) / 4;

		m_vecPosOfNode.push_back(pos);
	}
	// << 

	ASTAR->Setup(m_vecPosOfNode);

	// >> : �׸��� ����

	SHADOW->Setup(m_vecConstruct);
	
	// << :
}

void cMapManager::Update()
{
	if (m_pSkyBox) m_pSkyBox->Update(CAMERA->GetCamera());
}

void cMapManager::Render()
{
	static bool test = false;
	if (INPUT->IsKeyDown(VK_TAB))
	{
		if (test == false)
		{
			test = true;
		}
		else
		{
			test = false;
		}
	}

	if (test == false)
	{

		if (m_pSkyBox) m_pSkyBox->Render();

		if (m_pMap) m_pMap->Render();

		SHADOW->Render();
		for (int i = 0; i < m_vecConstruct.size(); i++)
		{
			m_vecConstruct[i]->Render();
		}
	}
	else { ASTAR->Render(); }
}

bool cMapManager::GetHeight(IN float x, OUT float & y, IN float z)
{
	if (m_pMap->GetHeight(x, y, z))return true;
	
	return false;
}

LPD3DXMESH cMapManager::GetMesh()
{
	return m_pMap->GetMesh();
}

float cMapManager::GetMaxX()
{
	return m_pMap->GetMaxX();
}

float cMapManager::GetMinX()
{
	return m_pMap->GetMinX();
}

void cMapManager::Destroy()
{
	SAFE_DELETE(m_pSkyBox);
	SAFE_DELETE(m_pMap);
	ASTAR->Release();
	for (int i = 0; i < m_vecConstruct.size(); i++)
	{
		SAFE_DELETE(m_vecConstruct[i]);
	}
	m_vecConstruct.clear();
	
}
