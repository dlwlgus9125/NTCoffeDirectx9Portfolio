#pragma once
#include "cUIObject.h"
class cUIInventory :
	public cUIObject
{
	// >> �ٵ�
	ST_SIZEN							m_stBodySize;
	D3DXVECTOR3							m_vPos_Body;
	LPDIRECT3DTEXTURE9					m_pTexture_Body;
	// <<

	// >> ����
	vector<ST_SLOT>						m_vecSlotInfo;
	vector<ST_SLOTDATA*>				m_vecShownData;
	FONT_TAG							m_eFont_Slot;
	// << 

	// >>  ���� ��ư					��ư �����ؾ� ��
	D3DXVECTOR3					m_vBtnPos;
	cUIButton*					m_pBtn_Exit;
	// <<
public:
	cUIInventory();
	~cUIInventory();

	virtual void Update(float deltaTime);
	virtual void Render(LPD3DXSPRITE pSprite);
	virtual void Destroy();

	void Setup_Tap(string sPath_body, D3DXVECTOR3 pos_body);
	void Setup_Slot(D3DXVECTOR3 rectPos, ST_SIZEN rectSize,	D3DXVECTOR3 imagePos, ST_SIZEN imageSize, D3DXVECTOR3 textPos, ST_SIZEN textSize, FONT_TAG eFont = FONT_DEF);
	void AddShownData(int itemSID);
	void DeleteShownData(int itemSID);
	HRESULT GetClickedItemID(OUT int& eventID, OUT int& itemID);
	void Setup_exitbtn(D3DXVECTOR3 btnPos, string sPath_idle, string sPath_mouseover, string sPath_clicked);
};

