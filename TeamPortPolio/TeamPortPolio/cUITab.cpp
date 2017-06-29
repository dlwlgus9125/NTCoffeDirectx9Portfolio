#include "stdafx.h"
#include "cUITab.h"
#include "cUIButton.h"


cUITab::cUITab() : m_pTexture_Body(NULL), m_pBtn_Exit(NULL), m_nFirstKeyInMap(-1), m_isNormal(true)
{
}


cUITab::~cUITab()
{
}

void cUITab::Setup_Tap(string sPath_idle_title, string sPath_selected_title, string sPath_body, D3DXVECTOR3 pos_body, FONT_TAG eFont)
{
	D3DXIMAGE_INFO imageInfo;
	m_mapTexture_Title[UI_IDLE] = TEXTURE->GetTexture(sPath_idle_title, imageInfo);
	m_mapTexture_Title[UI_SELECTED] = TEXTURE->GetTexture(sPath_selected_title, imageInfo);
	m_stTitleSize = ST_SIZEN(imageInfo.Width, imageInfo.Height);

	m_pTexture_Body = TEXTURE->GetTexture(sPath_body, imageInfo);
	m_vPos_Body = pos_body;
	m_stBodySize = ST_SIZEN(imageInfo.Width, imageInfo.Height);;

	m_eFont_Tab = eFont;
}

void cUITab::AddTitle(string title, D3DXVECTOR3 pos_title)
{
	D3DXVECTOR3 translated_pos_title = pos_title;
	ST_TAB tab = ST_TAB(title, translated_pos_title, UI_IDLE);
	m_vecTabInfo.push_back(tab);
}

void cUITab::SetDef()
{
	SetShownData(m_nFirstKeyInMap, 0);

	// >> �� ���� ��, ù��° �޴��� ���̵���
	m_vecTabInfo[0].state = UI_SELECTED;
	for (int i = 1; i < m_vecTabInfo.size(); i++)
	{
		m_vecTabInfo[i].state = UI_IDLE;
	}
	// << 
}

void cUITab::Update(float deltaTime)
{
	if(m_pBtn_Exit) m_pBtn_Exit->SetHidden(m_isHidden);
	if (m_isHidden) return;

	// >> ���� Ÿ��Ʋ Ŭ�� �� ��� �� Ÿ��Ʋ�� ���� �ٲ��ִ� �κ�
	if (INPUT->IsMouseDown(MOUSE_LEFT))
	{
		for (int i = 0; i < m_vecTabInfo.size(); i++)
		{
			D3DXVECTOR2 lt = D3DXVECTOR2(m_vecTabInfo[i].pos.x, m_vecTabInfo[i].pos.y);
			D3DXVECTOR2 rb = D3DXVECTOR2(m_vecTabInfo[i].pos.x + m_stTitleSize.nWidth, m_vecTabInfo[i].pos.y + m_stTitleSize.nHeight);

			if (MATH->IsCollided(INPUT->GetMousePosVector2(), lt, rb))
			{
				for (int k = 0; k < m_vecTabInfo.size(); k++)
				{
					if (k == i) m_vecTabInfo[i].state = UI_SELECTED;
					else m_vecTabInfo[k].state = UI_IDLE;
				}
				SetShownData(i + m_nFirstKeyInMap, 0);
				break;
			}
		}
	}	
	// <<

	// >> �����ư ������Ʈ �� Ŭ�� �� hidden�ǵ���
	if (m_pBtn_Exit)
	{
		m_pBtn_Exit->Update(deltaTime);
		if (m_pBtn_Exit->GetCurrentState() == UI_CLICKED) m_isHidden = true;
	}	
	// << 

	cUIObject::Update(deltaTime);
}

void cUITab::Render(LPD3DXSPRITE pSprite)
{
	if (m_isHidden) return;

	pSprite->SetTransform(&m_matWorld);
	RECT rc;

	// >> �ٵ� ����
	pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
	SetRect(&rc, 0, 0, m_stBodySize.nWidth, m_stBodySize.nHeight);
	pSprite->Draw(m_pTexture_Body, &rc, &D3DXVECTOR3(0, 0, 0), &m_vPos_Body, D3DCOLOR_ARGB(m_nAlpha, 255, 255, 255));
	pSprite->End();
	// << 
	
	// >> Ÿ��Ʋ ����	// ��������Ʈ���� �̹� ���� ������ ���� ���ϵ���
	//for (int i = 0; i < m_vecTabInfo.size(); i++)
	//{
	//	pSprite->SetTransform(&m_matWorld);
	//	pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
	//	SetRect(&rc, 0, 0, m_stTitleSize.nWidth, m_stTitleSize.nHeight);
	//	pSprite->Draw(m_mapTexture_Title[m_vecTabInfo[i].state], &rc, &D3DXVECTOR3(0, 0, 0), &m_vecTabInfo[i].pos, D3DCOLOR_ARGB(m_nAlpha, 255, 255, 255));
	//	pSprite->End();
	//}
	// << 	

	// ���� ��ư ����
	if (m_pBtn_Exit)
	{
		pSprite->SetTransform(&m_matWorld);
		pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
		m_pBtn_Exit->Render(pSprite);
		pSprite->End();
	}

	// >> ���� �̹���	
	for (int i = 0; i < m_vecShownData.size(); i++)
	{
		pSprite->SetTransform(&m_matWorld);
		pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_TEXTURE);
	
		// �׽�Ʈ��
		//SetRect(&rc, 0, 0, m_vecSlotInfo[i].rectSize.nWidth, m_vecSlotInfo[i].rectSize.nHeight);
		//pSprite->Draw(TEXTURE->GetTexture("image/rect/darkgray.png"), &rc, &D3DXVECTOR3(0, 0, 0), &(m_vecSlotInfo[i].imagePos), D3DCOLOR_ARGB(m_nAlpha, 255, 255, 255));
		
		D3DXIMAGE_INFO imageInfo;
		LPDIRECT3DTEXTURE9 texture = TEXTURE->GetTexture(m_vecShownData[i]->imagePath, imageInfo);
		SetRect(&rc, 0, 0, imageInfo.Width, imageInfo.Height);
		
		pSprite->Draw(texture, &rc, &D3DXVECTOR3(0, 0, 0), &(m_vecSlotInfo[i].imagePos), D3DCOLOR_ARGB(m_nAlpha, 255, 255, 255));
	
		pSprite->End();
	}
	// << 

	// >> Ÿ��Ʋ �۾� �μ� // ��������Ʈ���� �̹� ���� ������ ���� ���ϵ���
	//for (int i = 0; i < m_vecTabInfo.size(); i++)
	//{
	//	pSprite->SetTransform(&m_matWorld);
	//	LPD3DXFONT pFont = FONT->GetFont(m_eFont_Tab);
	//	SetRect(&rc, m_vPosition.x + m_vecTabInfo[i].pos.x, m_vPosition.y + m_vecTabInfo[i].pos.y,
	//		m_vPosition.x + m_vecTabInfo[i].pos.x + m_stTitleSize.nWidth, m_vPosition.y +  m_vecTabInfo[i].pos.y + m_stTitleSize.nHeight);
	//	pFont->DrawText(NULL, m_vecTabInfo[i].text.c_str(), m_vecTabInfo[i].text.length(), &rc, DT_CENTER | DT_VCENTER,
	//		m_vecTabInfo[i].state == UI_IDLE ? D3DCOLOR_XRGB(255, 255, 255) : D3DCOLOR_XRGB(255, 255, 0));
	//}
	// << 

	// >> ǰ��, ���� �μ�
	if (m_isNormal)
	{
		for (int i = 0; i < m_vecShownData.size(); i++)
		{
			pSprite->SetTransform(&m_matWorld);
			LPD3DXFONT pFont = FONT->GetFont(m_eFont_Slot);
			SetRect(&rc, m_vPosition.x + m_vecSlotInfo[i].textPos.x, m_vPosition.y + m_vecSlotInfo[i].textPos.y,
				m_vPosition.x + m_vecSlotInfo[i].textPos.x + m_vecSlotInfo[i].textSize.nWidth, m_vPosition.y + m_vecSlotInfo[i].textPos.y + m_vecSlotInfo[i].textSize.nHeight);

			string text = m_vecShownData[i]->name + "\n\n���� : " + to_string(m_vecShownData[i]->cost) + " ���";
			pFont->DrawText(NULL, text.c_str(), text.length(), &rc, DT_LEFT | DT_VCENTER, D3DCOLOR_XRGB(255, 255, 255));
		}
	}
	// << 
	// ������ ǰ��, ������ �ƴϸ� �̰� �μ�
	else
	{
		for (int i = 0; i < m_vecShownData.size(); i++)
		{
			pSprite->SetTransform(&m_matWorld);
			LPD3DXFONT pFont = FONT->GetFont(m_eFont_Slot);
			SetRect(&rc, m_vPosition.x + m_vecSlotInfo[i].textPos.x, m_vPosition.y + m_vecSlotInfo[i].textPos.y,
				m_vPosition.x + m_vecSlotInfo[i].textPos.x + m_vecSlotInfo[i].textSize.nWidth, m_vPosition.y + m_vecSlotInfo[i].textPos.y + m_vecSlotInfo[i].textSize.nHeight);

			string text = m_vecShownData[i]->name;
			pFont->DrawText(NULL, text.c_str(), text.length(), &rc, DT_LEFT | DT_VCENTER, D3DCOLOR_XRGB(255, 255, 255));
		}
	}

	cUIObject::Render(pSprite);
}

void cUITab::Destroy()
{
	for(map<int, vector<ST_SLOTDATA*>>::iterator it = m_mapVecSlotData.begin(); it != m_mapVecSlotData.end(); it++)
	{
		vector<ST_SLOTDATA*> vecSlotData = (*it).second;

		for (int i = 0; i < vecSlotData.size(); i++)
		{
			SAFE_DELETE(vecSlotData[i]);
		}
	}
	m_mapVecSlotData.clear();
	if(m_pBtn_Exit) m_pBtn_Exit->Destroy();
	cUIObject::Destroy();
}

void cUITab::Setup_Slot(D3DXVECTOR3 vSlotStartPos, int col, int slotCount, D3DXVECTOR3 rectPos, ST_SIZEN rectSize,
	D3DXVECTOR3 imagePos, ST_SIZEN imageSize, D3DXVECTOR3 textPos, ST_SIZEN textSize, FONT_TAG eFont, bool isNormal)
{
	m_vSlotStartPos = vSlotStartPos;

	for (int i = 0; i < slotCount / col; i++)
	{
		for (int k = 0; k < col; k++)
		{
			D3DXVECTOR3 currentRect = m_vSlotStartPos+ D3DXVECTOR3(rectSize.nWidth * k, rectSize.nHeight * i, rectPos.z);
			D3DXVECTOR3 currentImagePos = currentRect + imagePos;
			D3DXVECTOR3 currentTextPos = currentRect + textPos;
			ST_SLOT slot = ST_SLOT(currentRect, rectSize, currentImagePos, imageSize, currentTextPos, textSize);
			m_vecSlotInfo.push_back(slot);
		}
	}
	m_eFont_Slot = eFont;
	m_isNormal = isNormal;
}

void cUITab::AddSlotData(int itemMID, int itemSID, string name, string imagePath, string info, int cost)
{
	if (m_nFirstKeyInMap < 0) m_nFirstKeyInMap = itemMID;
	D3DXIMAGE_INFO imageinfo;
	LPDIRECT3DTEXTURE9 texture = TEXTURE->GetTexture(imagePath, imageinfo);

	ST_SLOTDATA* data = new ST_SLOTDATA(itemSID, name, imagePath, info,cost);
	
	if (m_mapVecSlotData.find(itemMID) == m_mapVecSlotData.end())
	{
		vector<ST_SLOTDATA*> vecSlotData;
		m_mapVecSlotData[itemMID] = vecSlotData;
	}

	m_mapVecSlotData[itemMID].push_back(data);
}

void cUITab::SetShownData(int itemMID, int startIndex)
{
	m_vecShownData.clear();

	if (m_mapVecSlotData.find(itemMID) == m_mapVecSlotData.end()) return;

	vector<ST_SLOTDATA*> vecSlotData = m_mapVecSlotData[itemMID];


	for (int i = startIndex; i < m_vecSlotInfo.size(); i++)
	{
		if (startIndex + i >= vecSlotData.size()) break;

		m_vecShownData.push_back(vecSlotData[i]);
	}
}

// ���� ���� ���̵��, ���õ� ������ ���̵� ��ȯ�ϴ� �Լ�
HRESULT cUITab::GetClickedItemID(OUT int& eventID, OUT int& itemID)
{
	if (m_isHidden) return false;

	eventID = -1;
	itemID = -1;

	if (INPUT->IsMouseDown(MOUSE_RIGHT))
	{
		for (int i = 0; i < m_vecShownData.size(); i++)
		{
			D3DXVECTOR2 vPos = D3DXVECTOR2(m_vPosition.x, m_vPosition.y);
			if (MATH->IsCollided(INPUT->GetMousePosVector2(), vPos + m_vecSlotInfo[i].LeftTop(), vPos + m_vecSlotInfo[i].RightBottom()))
			{
				eventID = m_eEventID;
				itemID = m_vecShownData[i]->itemID;
				return true;
			}
		}
	}
	return false;
}

void cUITab::Setup_exitbtn(D3DXVECTOR3 btnPos, string sPath_idle, string sPath_mouseover, string sPath_clicked)
{
	m_pBtn_Exit = new cUIButton;
	m_vBtnPos = m_vPosition + btnPos;
	m_pBtn_Exit->Setup(m_vBtnPos, UI_BUTTON);
	m_pBtn_Exit->Setup_Button(sPath_idle, sPath_mouseover, sPath_clicked, TOWN_BTN_SHOPEXIT);
}

void cUITab::ClearShownData()
{
	m_vecShownData.clear();	

	for (map<int, vector<ST_SLOTDATA*>>::iterator it = m_mapVecSlotData.begin(); it != m_mapVecSlotData.end(); it++)
	{
		//vector<ST_SLOTDATA*> vecData = (*it).second;		// �����. �̳��� ����°���
		for (int i = 0; i < (*it).second.size(); i++)
		{
			SAFE_DELETE((*it).second[i]);
		}
		(*it).second.clear();
	}
}

void cUITab::UpdateTroopCount(int melee, int bow, int cavalry)
{
	if (m_mapVecSlotData.size() < 1) return;
	if (m_mapVecSlotData[0].size() < 3) return;

	m_mapVecSlotData[0][0]->name = to_string(melee);
	m_mapVecSlotData[0][1]->name = to_string(bow);
	m_mapVecSlotData[0][2]->name = to_string(cavalry);

	SetShownData(0, 0);
}