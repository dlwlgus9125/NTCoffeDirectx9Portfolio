#pragma once
#include "cUIObject.h"

class cUIButton;

class cUITab :
	public cUIObject
{
	// >> ��
	vector<ST_TAB>	m_vecTabInfo;
	ST_SIZEN m_stTitleSize;
	ST_SIZEN m_stBodySize;
	D3DXVECTOR3 m_vPos_Body;
	map<int, LPDIRECT3DTEXTURE9> m_mapTexture_Title;
	LPDIRECT3DTEXTURE9 m_pTexture_Body;
	FONT_TAG m_eFont_Tab;
	// <<

	// >> ����
	D3DXVECTOR3							m_vSlotStartPos;
	vector<ST_SLOT>						m_vecSlotInfo;
	map<int, vector<ST_SLOTDATA*>>		m_mapVecSlotData;
	vector<ST_SLOTDATA*>				m_vecShownData;
	FONT_TAG							m_eFont_Slot;
	int									m_nFirstKeyInMap;		// m_mapVecSlotData�� ù��° Ű��
	// << 

	// >>  ���� ��ư					��ư �����ؾ� ��
	D3DXVECTOR3					m_vBtnPos;
	cUIButton*					m_pBtn_Exit;
	// <<
public:
	cUITab();
	~cUITab();

	// >> ��
	void Setup_Tap(string sPath_idle_title, string sPath_selected_title,  string sPath_body, D3DXVECTOR3 pos_body, FONT_TAG eFont = FONT_DEF);
	void AddTitle(string title, D3DXVECTOR3 pos_title);
	void SetDef();
	// << 
	virtual void Update(float deltaTime);
	virtual void Render(LPD3DXSPRITE pSprite);
	virtual void Destroy();

	// >> ����
	void Setup_Slot(D3DXVECTOR3	vSlotStartPos, int col, int slotCount, D3DXVECTOR3 rectPos, ST_SIZEN rectSize,
		D3DXVECTOR3 imagePos, ST_SIZEN imageSize, D3DXVECTOR3 textPos, ST_SIZEN textSize, FONT_TAG eFont = FONT_DEF);
	void AddSlotData(int itemMId, int itemSID, string name, string imagePath, string info);
	void SetShownData(int itemMID, int startIndex);
	HRESULT GetClickedItemID(OUT int& eventID, OUT int& itemID);
	// << 

	void Setup_exitbtn(D3DXVECTOR3 btnPos, string sPath_idle, string sPath_mouseover, string sPath_clicked);

	void ClearShownData();
};

