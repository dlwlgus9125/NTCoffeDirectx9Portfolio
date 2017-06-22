#include "stdafx.h"
#include "cConstruct.h"
#include "cObject.h"
#include "cMtlTex.h"
#include "cObjLoader.h"

cConstruct::cConstruct()
	: m_pObjMesh(NULL)
	, m_vScale(0.5f, 0.5f, 0.5f)
	, m_fRotX(0.0f), m_fRotY(0.0f), m_fRotZ(0.0f)
	, m_vPosition(0.0f, 0.0f, 0.0f)
{
}


cConstruct::~cConstruct()
{
}

void cConstruct::Setup(char* szFolder, char* szFile, bool isChecked)
{
	cObjLoader	l;
	if (isChecked == true)			m_pObjMesh = l.LoadMesh(m_vecObjMtlTex, szFolder, szFile, true);
	else if (isChecked == false)	m_pObjMesh = l.LoadMesh(m_vecObjMtlTex, szFolder, szFile);
}

void cConstruct::Update()
{
	D3DXMATRIXA16	matS, matR, matT;

	D3DXMatrixIdentity(&m_matWorld);
	D3DXMatrixIdentity(&matS);
	D3DXMatrixIdentity(&matR);
	D3DXMatrixIdentity(&matT);

	D3DXMatrixScaling(&matS, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixRotationYawPitchRoll(&matR, m_fRotY, m_fRotX, m_fRotZ);
	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y, m_vPosition.z);
	m_matWorld = matS *matR* matT;
	if(FRUSTUM->IsIn(m_vPosition))
	{

	}

	D3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld);


	for (int i = 0; i < m_vecObjMtlTex.size(); i++)
	{
	D3DXVECTOR3 vOut;
	D3DXVec3TransformCoord(&vOut, &vOut, &m_matWorld);
	m_vecVertex.push_back(vOut);
	}

}

void cConstruct::Render()
{
	D3DDevice->SetRenderState(D3DRS_LIGHTING, true);
	D3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);

	if (m_nSObjID >= E_S_OBJECTID_H_DW_START && m_nSObjID <= E_S_OBJECTID_H_DW_END ||
		m_nSObjID >= E_S_OBJECTID_P_DW_START && m_nSObjID <= E_S_OBJECTID_P_ETC_END)
	{
		D3DDevice->SetRenderState(D3DRS_ALPHATESTENABLE, TRUE);
		D3DDevice->SetRenderState(D3DRS_ALPHAREF, 0x00000088);
		D3DDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);
		D3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	}

	if (FRUSTUM->IsIn(m_vPosition))
	{
		for (size_t i = 0; i < m_vecObjMtlTex.size(); i++)
		{
			D3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld);
			D3DDevice->SetMaterial(&m_vecObjMtlTex[i]->GetMaterial());
			D3DDevice->SetTexture(0, m_vecObjMtlTex[i]->GetTexture());
			m_pObjMesh->DrawSubset(i);
		}
	}

	D3DDevice->SetRenderState(D3DRS_ALPHATESTENABLE, FALSE);
	D3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);
	D3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
	D3DDevice->SetRenderState(D3DRS_LIGHTING, false);
}

void cConstruct::Create(int sIndex)
{
	char* folder = OBJECTDB->GetMapObject(sIndex)->szFolder;
	char* file = OBJECTDB->GetMapObject(sIndex)->szFile;

	m_nSObjID = sIndex;

	if (sIndex >= E_S_OBJECTID_P_DW_START && sIndex <= E_S_OBJECTID_P_ETC_END
		|| sIndex >= E_S_OBJECTID_N_H_START && sIndex <= E_S_OBJECTID_N_O_END)
		Setup(folder, file, false);
	else Setup(folder, file, true);

	Update();
}

void cConstruct::Destroy()
{
	SAFE_RELEASE(m_pObjMesh);
	for each(auto p in m_vecObjMtlTex)
	{
		SAFE_RELEASE(p);
	}

	// delete this;
}

vector<ST_LINE_VERTEX> cConstruct::GetTranfromedVector(vector<D3DXVECTOR3> d)
{
	vector<ST_LINE_VERTEX>vecLineVertex;
	for (int i = 1; i < d.size(); i++)
	{
		vecLineVertex.push_back(ST_LINE_VERTEX(d[i - 1], d[i]));
	}

	return vecLineVertex;
}
