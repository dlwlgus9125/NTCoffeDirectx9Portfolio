#include "stdafx.h"
#include "cUIManager.h"

// Ÿ��Ʋ���� ���� UI ����
void cUIManager::Setup_TitleScene()
{
	// �̴ϸ�
	m_pMiniMap = new cUIMiniMap;
	m_pMiniMap->Setup(D3DXVECTOR3(WND_WIDTH * 0.25f, WND_HEIGHT * 0.10f, 0), UI_MINIMAP);
	m_pMiniMap->Setup_Image("image/UI/titlescene/minimap/testmap.png", 150);
	m_pMiniMap->SetAlpha(150);

	// �̴ϸʹ�ư 1
	cUIButton* pBtn_start = new cUIButton;
	pBtn_start->Setup(D3DXVECTOR3(50, m_pMiniMap->GetSize().nHeight, 0), UI_BUTTON);
	pBtn_start->Setup_Button("Image/UI/titlescene/button/formation_rect/idle.png", 
		"Image/UI/titlescene/button/formation_rect/mouseover.png", 
		"Image/UI/titlescene/button/formation_rect/selected.png", TITLE_BTN_FMT_RECT);
	m_vecEventBtn.push_back(pBtn_start);
	m_pMiniMap->AddChild(pBtn_start);

	// �̴ϸʹ�ư 2
	cUIButton* pBtn_Help = new cUIButton;
	pBtn_Help->Setup(D3DXVECTOR3(150, m_pMiniMap->GetSize().nHeight, 0), UI_BUTTON);
	pBtn_Help->Setup_Button("Image/UI/titlescene/button/formation_tri/idle.png",
		"Image/UI/titlescene/button/formation_tri/mouseover.png",
		"Image/UI/titlescene/button/formation_tri/selected.png", TITLE_BTN_FMT_TRI);
	m_vecEventBtn.push_back(pBtn_Help);
	m_pMiniMap->AddChild(pBtn_Help);

	// �̴ϸʹ�ư 3
	cUIButton* pBtn_Exit = new cUIButton;
	pBtn_Exit->Setup(D3DXVECTOR3(300, m_pMiniMap->GetSize().nHeight, 0), UI_BUTTON);
	pBtn_Exit->Setup_Button("Image/UI/titlescene/button/state_att/idle.png",
		"Image/UI/titlescene/button/state_att/mouseover.png",
		"Image/UI/titlescene/button/state_att/selected.png", TITLE_BTN_ATTSTATE);
	m_vecEventBtn.push_back(pBtn_Exit);
	m_pMiniMap->AddChild(pBtn_Exit);

	// �̴ϸʹ�ư 4
	cUIButton* pButton4 = new cUIButton;
	pButton4->Setup(D3DXVECTOR3(400, m_pMiniMap->GetSize().nHeight, 0), UI_BUTTON);
	pButton4->Setup_Button("Image/UI/titlescene/button/state_def/idle.png",
		"Image/UI/titlescene/button/state_def/mouseover.png",
		"Image/UI/titlescene/button/state_def/selected.png", TITLE_BTN_DEFSTATE);
	m_vecEventBtn.push_back(pButton4);
	m_pMiniMap->AddChild(pButton4);
}

void cUIManager::Setup_TownScene()
{
	// >> �κ��丮 ����
	cUITab* pTab_Inven = new cUITab();
	pTab_Inven->Setup(D3DXVECTOR3(WND_WIDTH - 300, 0, 0), UI_TAB);
	pTab_Inven->Setup_Tap("image/ui/townscene/tab_shop_inventory/idle.png", "image/ui/townscene/tab_shop_inventory/selected.png", "image/ui/townscene/tab_shop_inventory/body.png", D3DXVECTOR3(0, 0, 0));
	pTab_Inven->AddTitle("�κ��丮", D3DXVECTOR3(25, 475, 0));
	/// �κ��丮 ����
	pTab_Inven->Setup_Slot(D3DXVECTOR3(22, 90, 0), 1, 7, D3DXVECTOR3(0, 0, 0), ST_SIZEN(190, 55),
		D3DXVECTOR3(0, 0, 0), ST_SIZEN(50, 50), D3DXVECTOR3(55, 0, 0), ST_SIZEN(140, 50), FONT_SHOP);
	vector<int> vecInven = OBJECT->GetInventory();
	for (int i = 0; i < vecInven.size(); i++)
	{
		ST_ITEM* item = ITEMDB->GetItem(vecInven[i]);
		pTab_Inven->AddSlotData(I_M_INVENTORY, item->eSmallID, item->name, item->szImagePath, item->info, item->cost);
	}
	pTab_Inven->SetDef();
	/// �κ��丮 �����ư
	pTab_Inven->Setup_exitbtn(D3DXVECTOR3(244, 17, 0),
		"image/ui/townscene/tab_shop_inventory/btn_idle.png", "image/ui/townscene/tab_shop_inventory/btn_mouseover.png", "image/ui/townscene/tab_shop_inventory/btn_select.png");
	pTab_Inven->SetEventID(TOWN_TAB_INVENTORY);
	m_vecTab.push_back(pTab_Inven);
	// << 

	// >> ���� 1 �� �������
	cUITab* pTab_Weapon = new cUITab();
	pTab_Weapon->Setup(D3DXVECTOR3(0, 0, 0), UI_TAB);
	pTab_Weapon->Setup_Tap("image/ui/townscene/tab_shop_atk/idle.png", "image/ui/townscene/tab_shop_atk/selected.png", "image/ui/townscene/tab_shop_atk/body.png", D3DXVECTOR3(0, 0, 0));
	pTab_Weapon->AddTitle("��", D3DXVECTOR3(25, 475, 0));
	pTab_Weapon->AddTitle("����", D3DXVECTOR3(150, 475, 0));
	pTab_Weapon->AddTitle("Ȱ", D3DXVECTOR3(275, 475, 0));
	/// ���� 1 ���� �׽�Ʈ��
	pTab_Weapon->Setup_Slot(D3DXVECTOR3(22, 90, 0), 2, 14, D3DXVECTOR3(0, 0, 0), ST_SIZEN(190, 55),
		D3DXVECTOR3(0, 0, 0), ST_SIZEN(50, 50), D3DXVECTOR3(55, 0, 0), ST_SIZEN(140, 50), FONT_SHOP);
	for (int i = I_S_SWORD_SHORT_NOR; i <= I_S_SWORD_MITHRIL_GLZ; i++)
	{
		ST_ITEM* newItem = ITEMDB->GetItem(i);
		pTab_Weapon->AddSlotData(I_M_SWORD, newItem->eSmallID, newItem->name, newItem->szImagePath, newItem->info, newItem->cost);
	}
	for (int i = I_S_AXE_STONE; i <= I_S_AXE_HONORABLE; i++)
	{
		ST_ITEM* newItem = ITEMDB->GetItem(i);
		pTab_Weapon->AddSlotData(I_M_AXE, newItem->eSmallID, newItem->name, newItem->szImagePath, newItem->info, newItem->cost);
	}
	for (int i = I_S_BOW_WOODEN_NOR; i <= I_S_BOW_ELF_GLZ; i++)
	{
		ST_ITEM* newItem = ITEMDB->GetItem(i);
		pTab_Weapon->AddSlotData(I_M_BOW, newItem->eSmallID, newItem->name, newItem->szImagePath, newItem->info, newItem->cost);
	}
	pTab_Weapon->SetDef();
	/// ���� 1 �����ư
	pTab_Weapon->Setup_exitbtn(D3DXVECTOR3(382, 17, 0), 
		"image/ui/townscene/tab_shop_atk/btn_idle.png", "image/ui/townscene/tab_shop_atk/btn_mouseover.png", "image/ui/townscene/tab_shop_atk/btn_select.png");
	pTab_Weapon->SetEventID(TOWN_TAB_SHOP_ATT);
	m_vecTab.push_back(pTab_Weapon);
	// <<

	// >> ���� 2 �� �� ����
	cUITab* pTab_Armor = new cUITab();
	pTab_Armor->Setup(D3DXVECTOR3(0, 0, 0), UI_TAB);
	pTab_Armor->Setup_Tap("image/ui/townscene/tab_shop_def/idle.png", "image/ui/townscene/tab_shop_def/selected.png", "image/ui/townscene/tab_shop_def/body.png", D3DXVECTOR3(0, 0, 0));
	pTab_Armor->AddTitle("����", D3DXVECTOR3(25, 475, 0));
	pTab_Armor->AddTitle("����", D3DXVECTOR3(150, 475, 0));
	/// ���� 2 ���� �׽�Ʈ��
	pTab_Armor->Setup_Slot(D3DXVECTOR3(22, 90, 0), 2, 14, D3DXVECTOR3(0, 0, 0), ST_SIZEN(190, 55),
		D3DXVECTOR3(0, 0, 0), ST_SIZEN(50, 50), D3DXVECTOR3(55, 0, 0), ST_SIZEN(140, 50), FONT_SHOP);
	for (int i = I_S_ARMOR_OLD; i <= I_S_ARMOR_GENERAL_GLZ; i++)
	{
		ST_ITEM* newItem = ITEMDB->GetItem(i);
		pTab_Armor->AddSlotData(I_M_ARMOR, newItem->eSmallID, newItem->name, newItem->szImagePath, newItem->info, newItem->cost), newItem->cost;
	}
	for (int i = I_S_SHIELD_WOODEN_NOR; i <= I_S_SHIELD_HONORABLE; i++)
	{
		ST_ITEM* newItem = ITEMDB->GetItem(i);
		pTab_Armor->AddSlotData(I_M_SHIELD, newItem->eSmallID, newItem->name, newItem->szImagePath, newItem->info, newItem->cost);
	}
	pTab_Armor->SetDef();
	/// ���� 2 �����ư
	pTab_Armor->Setup_exitbtn(D3DXVECTOR3(382, 17, 0),
		"image/ui/townscene/tab_shop_def/btn_idle.png", "image/ui/townscene/tab_shop_def/btn_mouseover.png", "image/ui/townscene/tab_shop_def/btn_select.png");
	pTab_Armor->SetEventID(TOWN_TAB_SHOP_DEF);
	m_vecTab.push_back(pTab_Armor);
	// <<

	// �̴ϸ�
	m_pMiniMap = new cUIMiniMap;
	m_pMiniMap->Setup(D3DXVECTOR3(WND_WIDTH * 0.25f, WND_HEIGHT * 0.10f, 0), UI_MINIMAP);
	m_pMiniMap->Setup_Image("image/UI/titlescene/minimap/testmap.png", 150);
	m_pMiniMap->SetAlpha(150);
	m_pMiniMap->SetEventID(TOWN_MINIMAP);

	// �̴ϸ� ��ũ���� ��ư
	cUIButton* pBtn_Battle_Human = new cUIButton;
	pBtn_Battle_Human->Setup(D3DXVECTOR3(50, 150, 0), UI_BUTTON);
	pBtn_Battle_Human->Setup_Button("Image/UI/titlescene/button/formation_rect/idle.png",
		"Image/UI/titlescene/button/formation_rect/mouseover.png",
		"Image/UI/titlescene/button/formation_rect/selected.png", TOWN_BTN_BATTLE_ORC);
	m_vecEventBtn.push_back(pBtn_Battle_Human);
	m_pMiniMap->AddChild(pBtn_Battle_Human);

	// �̴ϸ� �޸����� ��ư
	cUIButton* pBtn_Battle_Orc = new cUIButton;
	pBtn_Battle_Orc->Setup(D3DXVECTOR3(300, 300, 0), UI_BUTTON);
	pBtn_Battle_Orc->Setup_Button("Image/UI/titlescene/button/formation_tri/idle.png",
		"Image/UI/titlescene/button/formation_tri/mouseover.png",
		"Image/UI/titlescene/button/formation_tri/selected.png", TOWN_BTN_BATTLE_HUMAN);
	m_vecEventBtn.push_back(pBtn_Battle_Orc);
	m_pMiniMap->AddChild(pBtn_Battle_Orc);
}

void cUIManager::Setup_LoginScene()
{
	// ���۹�ư
	cUIButton* pBtn_start = new cUIButton;
	pBtn_start->Setup(D3DXVECTOR3(550, 320, 0), UI_BUTTON);
	pBtn_start->Setup_Button("Image/UI/loginscene/StartButton/BT_STAND.png",
		"Image/UI/loginscene/StartButton/BT_MOUSE_OVER.png",
		"Image/UI/loginscene/StartButton/BT_SELECT.png", LOGIN_BTN_START);
	m_vecShownBtn.push_back(pBtn_start);
	m_vecEventBtn.push_back(pBtn_start);
	pBtn_start->SetHidden(false);

	// ���򸻹�ư
	cUIButton* pBtn_Help = new cUIButton;
	pBtn_Help->Setup(D3DXVECTOR3(550, 400, 0), UI_BUTTON);
	pBtn_Help->Setup_Button("Image/UI/loginscene/HelpButton/BT_STAND.png",
		"Image/UI/loginscene/HelpButton/BT_MOUSE_OVER.png",
		"Image/UI/loginscene/HelpButton/BT_SELECT.png", LOGIN_BTN_HELP);
	m_vecShownBtn.push_back(pBtn_Help);
	m_vecEventBtn.push_back(pBtn_Help);
	pBtn_Help->SetHidden(false);

	// �����ư
	cUIButton* pBtn_Exit = new cUIButton;
	pBtn_Exit->Setup(D3DXVECTOR3(550, 480, 0), UI_BUTTON);
	pBtn_Exit->Setup_Button("Image/UI/loginscene/ExitButton/BT_STAND.png",
		"Image/UI/loginscene/ExitButton/BT_MOUSE_OVER.png",
		"Image/UI/loginscene/ExitButton/BT_SELECT.png", LOGIN_BTN_EXIT);
	m_vecShownBtn.push_back(pBtn_Exit);
	m_vecEventBtn.push_back(pBtn_Exit);
	pBtn_Exit->SetHidden(false);
}

void cUIManager::Setup_SelectScene()
{
	// �� ���� ������ ���ý� ���� �� �̹����� ����Ʈ�����̹����� ����������.
	// ��ũ
	cUIButton* pBtn_Orc = new cUIButton;
	pBtn_Orc->Setup(D3DXVECTOR3(650, 545, 0), UI_BUTTON);
	pBtn_Orc->Setup_Button("Image/UI/SelectScene/Icon/Horde.png",
		"Image/UI/SelectScene/Icon/Horde_Over.png",
		"Image/UI/SelectScene/Icon/Horde_Select.png", SELECT_BTN_ORC);
	m_vecShownBtn.push_back(pBtn_Orc);
	m_vecEventBtn.push_back(pBtn_Orc);
	pBtn_Orc->SetHidden(false);

	// �޸�
	cUIButton* pBtn_Human = new cUIButton;
	pBtn_Human->Setup(D3DXVECTOR3(500, 545, 0), UI_BUTTON);
	pBtn_Human->Setup_Button("Image/UI/SelectScene/Icon/Alliance.png",
		"Image/UI/SelectScene/Icon/Alliance_Over.png",
		"Image/UI/SelectScene/Icon/Alliance_Select.png", SELECT_BTN_HUMAN);
	m_vecShownBtn.push_back(pBtn_Human);
	m_vecEventBtn.push_back(pBtn_Human);
	pBtn_Human->SetHidden(false);

	// ���� ����
	cUIButton* pBtn_Start = new cUIButton;
	pBtn_Start->Setup(D3DXVECTOR3(950, 630, 0), UI_BUTTON);
	pBtn_Start->Setup_Button("Image/UI/SelectScene/Button/Character_BT/BT_STAND.png",
		"Image/UI/SelectScene/Button/Character_BT/BT_MOUSE_OVER.png",
		"Image/UI/SelectScene/Button/Character_BT/BT_SELECT.png", SELECT_BTN_CREATE);
	m_vecShownBtn.push_back(pBtn_Start);
	m_vecEventBtn.push_back(pBtn_Start);
	pBtn_Start->SetHidden(false);

	// ���ư���
	cUIButton* pBtn_Back = new cUIButton;
	pBtn_Back->Setup(D3DXVECTOR3(1100, 630, 0), UI_BUTTON);
	pBtn_Back->Setup_Button("Image/UI/SelectScene/Button/SCENE_BACK/BT_STAND.png",
		"Image/UI/SelectScene/Button/SCENE_BACK/BT_MOUSE_OVER.png",
		"Image/UI/SelectScene/Button/SCENE_BACK/BT_SELECT.png", SELECT_BTN_BACK);
	m_vecShownBtn.push_back(pBtn_Back);
	m_vecEventBtn.push_back(pBtn_Back);
	pBtn_Back->SetHidden(false);

	// ��ũ ���� â
	cUIMsgBox* pMsgBox_Human = new cUIMsgBox;
	pMsgBox_Human->Setup(D3DXVECTOR3(930, 50, 0), UI_MSGBOX);
	pMsgBox_Human->Setup_MsgBox("image/ui/selectscene/msgbox_orc/msgbox_human_bg.png", D3DXVECTOR3(50, 50, 0), ST_SIZEN(250, 500), SELECT_MSGBOX_ORC, FONT_SHOP);
	pMsgBox_Human->Setup_Text("�ΰ��̴�\n���� �߻��������\n�ٵ� ���� ���� �̳�?");
	m_vecMsg.push_back(pMsgBox_Human);

	// �޸� ���� â
	cUIMsgBox* pMsgBox_Orc = new cUIMsgBox;
	pMsgBox_Orc->Setup(D3DXVECTOR3(930, 50, 0), UI_MSGBOX);
	pMsgBox_Orc->Setup_MsgBox("image/ui/selectscene/msgbox_orc/msgbox_orc_bg.png", D3DXVECTOR3(50, 50, 0), ST_SIZEN(250, 500), SELECT_MSGBOX_HUMAN, FONT_SHOP);
	pMsgBox_Orc->Setup_Text("��ũ�� �پ�ٴϴ� ����\n�ܲܰŸ��鼭\n�޷����� ������ ��\n���� ����.");
	m_vecMsg.push_back(pMsgBox_Orc);
}

void cUIManager::Setup_BattleScene_Orc()
{
	// �̴ϸ�
	m_pMiniMap = new cUIMiniMap;
	m_pMiniMap->Setup(D3DXVECTOR3(WND_WIDTH * 0.25f, WND_HEIGHT * 0.10f, 0), UI_MINIMAP);
	m_pMiniMap->Setup_Image("image/UI/BattleScene_Orc/minimap/ground.png", 150);
	m_pMiniMap->SetAlpha(150);

	// �̴ϸʹ�ư 1
	cUIButton* pBtn_start = new cUIButton;
	pBtn_start->Setup(D3DXVECTOR3(50, m_pMiniMap->GetSize().nHeight, 0), UI_BUTTON);
	pBtn_start->Setup_Button("Image/UI/titlescene/button/formation_rect/idle.png",
		"Image/UI/titlescene/button/formation_rect/mouseover.png",
		"Image/UI/titlescene/button/formation_rect/selected.png", TITLE_BTN_FMT_RECT);
	m_vecEventBtn.push_back(pBtn_start);
	m_pMiniMap->AddChild(pBtn_start);

	// �̴ϸʹ�ư 2
	cUIButton* pBtn_Help = new cUIButton;
	pBtn_Help->Setup(D3DXVECTOR3(150, m_pMiniMap->GetSize().nHeight, 0), UI_BUTTON);
	pBtn_Help->Setup_Button("Image/UI/titlescene/button/formation_tri/idle.png",
		"Image/UI/titlescene/button/formation_tri/mouseover.png",
		"Image/UI/titlescene/button/formation_tri/selected.png", TITLE_BTN_FMT_TRI);
	m_vecEventBtn.push_back(pBtn_Help);
	m_pMiniMap->AddChild(pBtn_Help);

	// �̴ϸʹ�ư 3
	cUIButton* pBtn_Exit = new cUIButton;
	pBtn_Exit->Setup(D3DXVECTOR3(300, m_pMiniMap->GetSize().nHeight, 0), UI_BUTTON);
	pBtn_Exit->Setup_Button("Image/UI/titlescene/button/state_att/idle.png",
		"Image/UI/titlescene/button/state_att/mouseover.png",
		"Image/UI/titlescene/button/state_att/selected.png", TITLE_BTN_ATTSTATE);
	m_vecEventBtn.push_back(pBtn_Exit);
	m_pMiniMap->AddChild(pBtn_Exit);

	// �̴ϸʹ�ư 4
	cUIButton* pButton4 = new cUIButton;
	pButton4->Setup(D3DXVECTOR3(400, m_pMiniMap->GetSize().nHeight, 0), UI_BUTTON);
	pButton4->Setup_Button("Image/UI/titlescene/button/state_def/idle.png",
		"Image/UI/titlescene/button/state_def/mouseover.png",
		"Image/UI/titlescene/button/state_def/selected.png", TITLE_BTN_DEFSTATE);
	m_vecEventBtn.push_back(pButton4);
	m_pMiniMap->AddChild(pButton4);
}

void cUIManager::Setup_BattleScene_Human()
{
	// �̴ϸ�
	m_pMiniMap = new cUIMiniMap;
	m_pMiniMap->Setup(D3DXVECTOR3(WND_WIDTH * 0.25f, WND_HEIGHT * 0.10f, 0), UI_MINIMAP);
	m_pMiniMap->Setup_Image("image/UI/BattleScene_Human/minimap/ground3.png", 150);
	m_pMiniMap->SetAlpha(150);

	// �̴ϸʹ�ư 1
	cUIButton* pBtn_start = new cUIButton;
	pBtn_start->Setup(D3DXVECTOR3(50, m_pMiniMap->GetSize().nHeight, 0), UI_BUTTON);
	pBtn_start->Setup_Button("Image/UI/titlescene/button/formation_rect/idle.png",
		"Image/UI/titlescene/button/formation_rect/mouseover.png",
		"Image/UI/titlescene/button/formation_rect/selected.png", TITLE_BTN_FMT_RECT);
	m_vecEventBtn.push_back(pBtn_start);
	m_pMiniMap->AddChild(pBtn_start);

	// �̴ϸʹ�ư 2
	cUIButton* pBtn_Help = new cUIButton;
	pBtn_Help->Setup(D3DXVECTOR3(150, m_pMiniMap->GetSize().nHeight, 0), UI_BUTTON);
	pBtn_Help->Setup_Button("Image/UI/titlescene/button/formation_tri/idle.png",
		"Image/UI/titlescene/button/formation_tri/mouseover.png",
		"Image/UI/titlescene/button/formation_tri/selected.png", TITLE_BTN_FMT_TRI);
	m_vecEventBtn.push_back(pBtn_Help);
	m_pMiniMap->AddChild(pBtn_Help);

	// �̴ϸʹ�ư 3
	cUIButton* pBtn_Exit = new cUIButton;
	pBtn_Exit->Setup(D3DXVECTOR3(300, m_pMiniMap->GetSize().nHeight, 0), UI_BUTTON);
	pBtn_Exit->Setup_Button("Image/UI/titlescene/button/state_att/idle.png",
		"Image/UI/titlescene/button/state_att/mouseover.png",
		"Image/UI/titlescene/button/state_att/selected.png", TITLE_BTN_ATTSTATE);
	m_vecEventBtn.push_back(pBtn_Exit);
	m_pMiniMap->AddChild(pBtn_Exit);

	// �̴ϸʹ�ư 4
	cUIButton* pButton4 = new cUIButton;
	pButton4->Setup(D3DXVECTOR3(400, m_pMiniMap->GetSize().nHeight, 0), UI_BUTTON);
	pButton4->Setup_Button("Image/UI/titlescene/button/state_def/idle.png",
		"Image/UI/titlescene/button/state_def/mouseover.png",
		"Image/UI/titlescene/button/state_def/selected.png", TITLE_BTN_DEFSTATE);
	m_vecEventBtn.push_back(pButton4);
	m_pMiniMap->AddChild(pButton4);
}

void cUIManager::Setup()
{
	m_pMiniMap = NULL;
}

void cUIManager::Release()
{	
	m_vecShownBtn.clear();
	for each(auto p in m_vecEventBtn)
	{
		p->Destroy();
	}
	m_vecEventBtn.clear();
	for each(auto p in m_vecTab)
	{
		p->Destroy();
	}
	m_vecTab.clear();
	for each(auto p in m_vecMsg)
	{
		p->Destroy();
	}
	m_vecMsg.clear();
	
	SAFE_DELETE(m_pMiniMap);
}

void cUIManager::Update(float deltaTime)
{
	PressKey();

	if(m_pMiniMap) m_pMiniMap->Update(deltaTime);

	for (int i = 0; i < m_vecTab.size(); i++)
	{
		m_vecTab[i]->Update(deltaTime);
	}

	for (int i = 0; i < m_vecShownBtn.size(); i++)
	{
		m_vecShownBtn[i]->Update(deltaTime);
	}

	for (int i = 0; i < m_vecMsg.size(); i++)
	{
		m_vecMsg[i]->Update(deltaTime);
	}
}

void cUIManager::Render(LPD3DXSPRITE pSprite)
{
	if (m_pMiniMap) m_pMiniMap->Render(pSprite);

	for (int i = 0; i < m_vecTab.size(); i++)
	{
		m_vecTab[i]->Render(pSprite);
	}

	for (int i = 0; i < m_vecShownBtn.size(); i++)
	{
		m_vecShownBtn[i]->Render(pSprite);
	}

	for (int i = 0; i < m_vecMsg.size(); i++)
	{
		m_vecMsg[i]->Render(pSprite);
	}
}

// �� ���濡 ���� UI ��ü �����Ű�� �Լ�
void cUIManager::Change(int sceneID)
{
	Release();

	switch (sceneID)
	{
	case SCENE_TITLE:
		Setup_TitleScene();
		break;
	case SCENE_TOWN:
		Setup_TownScene();
		break;
	case SCENE_LOGIN:
		Setup_LoginScene();
		break;
	case SCENE_SELECT:
		Setup_SelectScene();
		break;
	case SCENE_BATTLE_HUMAN:
		Setup_BattleScene_Human();
		break;
	case SCENE_BATTLE_ORC:
		Setup_BattleScene_Orc();
		break;
	}
}

void cUIManager::PressKey()
{
	if (INPUT->IsKeyDown(VK_CONTROL) && m_pMiniMap)
	{
		m_pMiniMap->SetHiddenAll(!(m_pMiniMap->GetHidden()));
	}


	if (INPUT->IsKeyDown(VK_F3)) m_vecTab[0]->SetHiddenAll(!(m_vecTab[0]->GetHidden()));
}

void cUIManager::SetEvent(int uiID, int order)
{
	switch (uiID)
	{
	case TOWN_TAB_SHOP_ATT:
		m_vecTab[0]->SetHidden(order);
		m_vecTab[0]->SetDef();
		m_vecTab[1]->SetHidden(order);
		m_vecTab[1]->SetDef();
		break;
	case TOWN_TAB_SHOP_DEF:
		m_vecTab[0]->SetHidden(order);
		m_vecTab[0]->SetDef();
		m_vecTab[2]->SetHidden(order);
		m_vecTab[2]->SetDef();
		break;
	case TOWN_MINIMAP:
		if (m_pMiniMap) m_pMiniMap->SetHiddenAll(order);
		break;
	case SELECT_MSGBOX_ORC:
		m_vecMsg[0]->SetHidden(order);
		break;
	case SELECT_MSGBOX_HUMAN:
		m_vecMsg[1]->SetHidden(order);
		break;
	}

}

void cUIManager::GetEvent(OUT int& minimapIndex, OUT int& buttonIndex, OUT int& eventID, OUT int& itemID)
{
	// �̴ϸ� ��Ŭ�� �� ����� �ε��� ��ȯ���ִ� �κ�
	if(m_pMiniMap) minimapIndex = m_pMiniMap->GetIndex();

	// ��ư �� Ŭ���� �༮�� �ε��� ��ȯ���ִ� �κ�
	buttonIndex = -1;
	for (int i = 0; i < m_vecEventBtn.size(); i++)
	{
		if (m_vecEventBtn[i]->GetCurrentState() == UI_CLICKED)
		{
			buttonIndex = m_vecEventBtn[i]->GetEventID();
			break;
		}		
	}

	// �� �� Ŭ���� ���� ������ ���̵� ��ȯ�ϴ� �κ�
	eventID = -1;
	itemID = -1;
	for (int i = 0; i < m_vecTab.size(); i++)
	{
		if(m_vecTab[i]->GetClickedItemID(eventID, itemID)) break;
	}
}

void cUIManager::Setup_Inventory()
{
	// �κ��丮 �ʱ�ȭ
	m_vecTab[0]->ClearShownData();
	// �κ��丮 ���� �����
	vector<int> vecInven = OBJECT->GetInventory();
	for (int i = 0; i < vecInven.size(); i++)
	{
		ST_ITEM* item = ITEMDB->GetItem(vecInven[i]);
		m_vecTab[0]->AddSlotData(I_M_INVENTORY, item->eSmallID, item->name, item->szImagePath, item->info, item->cost);
	}
	m_vecTab[0]->SetDef();
}