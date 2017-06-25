#pragma once
#include "cUIObject.h"

class cUIButton;

class cUIMiniMap :
	public cUIObject
{
	LPDIRECT3DTEXTURE9 m_pTexture;
	SYNTHESIZE(int, m_nAlpha, Alpha);
	int m_nCellPerRow;

	// >>  ���� ��ư					��ư �����ؾ� ��
	D3DXVECTOR3					m_vBtnPos;
	cUIButton*					m_pBtn_Exit;
	// <<

	ST_SIZEN m_stBGSize;
	D3DXVECTOR3 m_vBGPos;
	LPDIRECT3DTEXTURE9 m_pTex_BG;

	ST_SIZEN m_stLocationSize;				// �̴ϸ� �󿡼� �ɸ��� ��ġ ��Ÿ���� �༮
	D3DXVECTOR3 m_vLocationPos;
	LPDIRECT3DTEXTURE9 m_pTex_Location;

	ST_SIZEN m_stLocationSize_unit;				// �̴ϸ� �󿡼� �뺴 ��ġ ��Ÿ���� �༮
	D3DXVECTOR3 m_vLocationPos_unit;
	LPDIRECT3DTEXTURE9 m_pTex_Location_unit;

	ST_SIZEN m_stLocationSize_enemy;				// �̴ϸ� �󿡼� �� ��ġ ��Ÿ���� �༮
	D3DXVECTOR3 m_vLocationPos_enemy;
	LPDIRECT3DTEXTURE9 m_pTex_Location_enemy;
public:
	cUIMiniMap();
	~cUIMiniMap();

	virtual void Update(float deltaTime);
	virtual void Render(LPD3DXSPRITE pSprite);
	virtual void Destroy();

	void Setup_Image(string imagePath, int nCellPerRow);
	int GetIndex();

	void Setup_exitbtn(D3DXVECTOR3 btnPos, string sPath_idle, string sPath_mouseover, string sPath_clicked);
	void Setup_BG(D3DXVECTOR3 bgPos, string sPath);
	void Setup_Location(string sPath, string sPath_unit, string sPath_enemy);
	void Update_Location(D3DXVECTOR2 pos_uv, D3DXVECTOR2 pos_uv_unit, D3DXVECTOR2 pos_uv_eneny);
};

