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
	cUIButton* pBtn_rect = new cUIButton;
	pBtn_rect->Setup(D3DXVECTOR3(50, m_pMiniMap->GetSize().nHeight, 0), UI_BUTTON);
	pBtn_rect->Setup_Button("Image/UI/titlescene/button/formation_rect/idle.png",
		"Image/UI/titlescene/button/formation_rect/mouseover.png", 
		"Image/UI/titlescene/button/formation_rect/selected.png", TITLE_BTN_FMT_RECT);
	m_vecEventBtn.push_back(pBtn_rect);
	pBtn_rect->AddChild(pBtn_rect);

	// �̴ϸʹ�ư 2
	cUIButton* pBtn_tri = new cUIButton;
	pBtn_tri->Setup(D3DXVECTOR3(150, m_pMiniMap->GetSize().nHeight, 0), UI_BUTTON);
	pBtn_tri->Setup_Button("Image/UI/titlescene/button/formation_tri/idle.png",
		"Image/UI/titlescene/button/formation_tri/mouseover.png",
		"Image/UI/titlescene/button/formation_tri/selected.png", TITLE_BTN_FMT_TRI);
	m_vecEventBtn.push_back(pBtn_tri);
	m_pMiniMap->AddChild(pBtn_tri);

	// �̴ϸʹ�ư 3
	cUIButton* pBtn_atk = new cUIButton;
	pBtn_atk->Setup(D3DXVECTOR3(300, m_pMiniMap->GetSize().nHeight, 0), UI_BUTTON);
	pBtn_atk->Setup_Button("Image/UI/titlescene/button/state_att/idle.png",
		"Image/UI/titlescene/button/state_att/mouseover.png",
		"Image/UI/titlescene/button/state_att/selected.png", TITLE_BTN_ATTSTATE);
	m_vecEventBtn.push_back(pBtn_atk);
	m_pMiniMap->AddChild(pBtn_atk);

	// �̴ϸʹ�ư 4
	cUIButton* pBtn_def = new cUIButton;
	pBtn_def->Setup(D3DXVECTOR3(400, m_pMiniMap->GetSize().nHeight, 0), UI_BUTTON);
	pBtn_def->Setup_Button("Image/UI/titlescene/button/state_def/idle.png",
		"Image/UI/titlescene/button/state_def/mouseover.png",
		"Image/UI/titlescene/button/state_def/selected.png", TITLE_BTN_DEFSTATE);
	m_vecEventBtn.push_back(pBtn_def);
	m_pMiniMap->AddChild(pBtn_def);
}

void cUIManager::Setup_TownScene()
{
	// >> �κ��丮 ���� : ���� ���ſ�
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

	// >> �κ��丮 ���� : ������ �����
	cUITab* pTab_Inven_Equip = new cUITab();
	pTab_Inven_Equip->Setup(D3DXVECTOR3(WND_WIDTH - 285, 0, 0), UI_TAB);
	pTab_Inven_Equip->Setup_Tap("image/ui/townscene/tab_shop_inventory/idle.png", "image/ui/townscene/tab_shop_inventory/selected.png", "image/ui/townscene/tab_shop_inventory/body.png", D3DXVECTOR3(0, 0, 0));
	pTab_Inven_Equip->AddTitle("�κ��丮", D3DXVECTOR3(25, 475, 0));
	/// �κ��丮 ����
	pTab_Inven_Equip->Setup_Slot(D3DXVECTOR3(22, 90, 0), 1, 7, D3DXVECTOR3(0, 0, 0), ST_SIZEN(190, 55),
		D3DXVECTOR3(0, 0, 0), ST_SIZEN(50, 50), D3DXVECTOR3(55, 0, 0), ST_SIZEN(140, 50), FONT_SHOP);
	vector<int> vecInven_Equip = OBJECT->GetInventory();
	for (int i = 0; i < vecInven_Equip.size(); i++)
	{
		ST_ITEM* item = ITEMDB->GetItem(vecInven_Equip[i]);
		pTab_Inven_Equip->AddSlotData(I_M_INVENTORY, item->eSmallID, item->name, item->szImagePath, item->info, item->cost);
	}
	pTab_Inven_Equip->SetDef();
	/// �κ��丮 �����ư
	pTab_Inven_Equip->Setup_exitbtn(D3DXVECTOR3(244, 17, 0),
		"image/ui/townscene/tab_shop_inventory/btn_idle.png", "image/ui/townscene/tab_shop_inventory/btn_mouseover.png", "image/ui/townscene/tab_shop_inventory/btn_select.png");
	pTab_Inven_Equip->SetEventID(TOWN_TAB_INVENTORY_EQUIP);
	m_vecTab.push_back(pTab_Inven_Equip);
	// << 

	// >> ¡����
	cUITab* pTab_Recruit = new cUITab();
	pTab_Recruit->Setup(D3DXVECTOR3(0, 0, 0), UI_TAB);
	pTab_Recruit->Setup_Tap("image/ui/townscene/tab_recruit/idle.png", "image/ui/townscene/tab_recruit/selected.png", "image/ui/townscene/tab_recruit/body.png", D3DXVECTOR3(0, 0, 0));
	pTab_Recruit->AddTitle("���� ���", D3DXVECTOR3(25, 475, 0));
	/// ¡���� ���� �׽�Ʈ��
	pTab_Recruit->Setup_Slot(D3DXVECTOR3(22, 90, 0), 1, 5, D3DXVECTOR3(0, 0, 0), ST_SIZEN(190, 55),
		D3DXVECTOR3(0, 0, 0), ST_SIZEN(50, 50), D3DXVECTOR3(55, 0, 0), ST_SIZEN(140, 50), FONT_SHOP);

	///�޸��� ���
	if (OBJECT->GetPlayerID() == C_C_HUMAN_MALE)
	{
		for (int i = C_C_HUMAN_MELEE; i <= C_C_HUMAN_CAVALRY; i++)
		{
			if(i == C_C_HUMAN_MELEE)
				pTab_Recruit->AddSlotData(C_C_HUMAN_MALE, i, "�ΰ� ����", "", "Į�� ���з� �⺻���� ����", 2000);
			if (i == C_C_HUMAN_BOWMAN)
				pTab_Recruit->AddSlotData(C_C_HUMAN_MALE, i, "�ΰ� �ú�", "", "���Ÿ� ������ �̿��� �������� ����", 2000);
			if (i == C_C_HUMAN_CAVALRY)
				pTab_Recruit->AddSlotData(C_C_HUMAN_MALE, i, "�ΰ� �⺴", "", "���� ���ݷ����� ���������� ���� ����", 3000);
		}
	}
	/// ��ũ�� ���
	else if(OBJECT->GetPlayerID() == C_C_ORC_MALE)
	{
		for (int i = C_C_ORC_MELEE; i <= C_C_ORC_CAVALRY; i++)
		{
			if (i == C_C_ORC_MELEE)
				pTab_Recruit->AddSlotData(C_C_ORC_MALE, i, "��ũ ����", "", "�ڽ��� ������� �ϴ� ����", 2000);
			if (i == C_C_ORC_BOWMAN)
				pTab_Recruit->AddSlotData(C_C_ORC_MALE, i, "��ũ �ú�", "", "��� ���� �ź��� ���ϴ� ����", 2000);
			if (i == C_C_ORC_CAVALRY)
				pTab_Recruit->AddSlotData(C_C_ORC_MALE, i, "�׷�", "", "�ڽ��� ü���� ����� �� �� �ƴ� ����", 3000);
		}
	}

	pTab_Recruit->SetDef();
	/// ¡���� �����ư
	pTab_Recruit->Setup_exitbtn(D3DXVECTOR3(382, 17, 0),
		"image/ui/townscene/tab_recruit/btn_idle.png", "image/ui/townscene/tab_recruit/btn_mouseover.png", "image/ui/townscene/tab_recruit/btn_select.png");
	pTab_Recruit->SetEventID(TOWN_TAB_RECRUIT);
	m_vecTab.push_back(pTab_Recruit);
	// <<

	// >> ���â
	m_pInven = new cUIInventory;
	m_pInven->Setup(D3DXVECTOR3(0, 0, 0), UI_INVENTORY);
	m_pInven->Setup_Tap("image/ui/townscene/inventory/body.png", D3DXVECTOR3(0, 0, 0));
	m_pInven->Setup_Slot(D3DXVECTOR3(236, 258, 0), ST_SIZEN(55, 55), D3DXVECTOR3(0,0,0), ST_SIZEN(50, 50));
	m_pInven->Setup_Slot(D3DXVECTOR3(38, 258, 0), ST_SIZEN(55, 55), D3DXVECTOR3(0, 0, 0), ST_SIZEN(50, 50));
	m_pInven->Setup_Slot(D3DXVECTOR3(137, 153, 0), ST_SIZEN(55, 55), D3DXVECTOR3(0, 0, 0), ST_SIZEN(50, 50));
	m_pInven->Setup_exitbtn(D3DXVECTOR3(205, 467, 0),
		"image/ui/townscene/inventory/btn_idle.png", "image/ui/townscene/inventory/btn_mouseover.png", "image/ui/townscene/inventory/btn_select.png");
	m_pInven->SetEventID(TOWN_INVENTORY);
	// <<

	// �̴ϸ�
	m_pMiniMap = new cUIMiniMap;
	m_pMiniMap->Setup(D3DXVECTOR3(WND_WIDTH * 0.25f, WND_HEIGHT * 0.10f, 0), UI_MINIMAP);
	if(OBJECT->GetPlayerID() == C_C_HUMAN_MALE) m_pMiniMap->Setup_Image("image/UI/townscene/minimap/minimap_human.png", 150);
	else if (OBJECT->GetPlayerID() == C_C_ORC_MALE)  m_pMiniMap->Setup_Image("image/UI/townscene/minimap/minimap_orc.png", 150);
	m_pMiniMap->Setup_exitbtn(D3DXVECTOR3(674, 0, 0),
		"image/ui/townscene/minimap/btn_idle.png", "image/ui/townscene/minimap/btn_mouseover.png", "image/ui/townscene/minimap/btn_select.png");
	m_pMiniMap->SetEventID(TOWN_MINIMAP);

	// �̴ϸ� ��ũ���� ��ư
	cUIButton* pBtn_Battle_Orc = new cUIButton;
	pBtn_Battle_Orc->Setup(D3DXVECTOR3(205, 55, 0), UI_BUTTON);
	pBtn_Battle_Orc->Setup_Button("Image/UI/townscene/minimap/idle.png",
		"Image/UI/townscene/minimap/mouseover.png",
		"Image/UI/townscene/minimap/selected.png", TOWN_BTN_BATTLE_ORC);
	m_vecEventBtn.push_back(pBtn_Battle_Orc);
	m_pMiniMap->AddChild(pBtn_Battle_Orc);

	// �̴ϸ� �޸����� ��ư
	cUIButton* pBtn_Battle_Human = new cUIButton;
	pBtn_Battle_Human->Setup(D3DXVECTOR3(370, 215, 0), UI_BUTTON);
	pBtn_Battle_Human->Setup_Button("Image/UI/townscene/minimap/idle.png",
		"Image/UI/townscene/minimap/mouseover.png",
		"Image/UI/townscene/minimap/selected.png", TOWN_BTN_BATTLE_HUMAN);
	m_vecEventBtn.push_back(pBtn_Battle_Human);
	m_pMiniMap->AddChild(pBtn_Battle_Human);

	// >> ü�� ���� ǥ�� ����
	m_pStatus = new cUIProgressBar;
	m_pStatus->Setup(D3DXVECTOR3(0, 0, 0.0f), UI_PROGRESSBAR);
	if (OBJECT->GetPlayerID() == C_C_HUMAN_MALE) m_pStatus->Setup_Progress("Image/UI/townscene/bar_status/status_human.png", "", D3DXVECTOR3(30, 20, 0));
	else if (OBJECT->GetPlayerID() == C_C_ORC_MALE) m_pStatus->Setup_Progress("Image/UI/townscene/bar_status/status_orc.png", "", D3DXVECTOR3(30, 20, 0));
	m_pStatus->AddProgressBar("Image/UI/townscene/bar_status/life.png", D3DXVECTOR3(148, 33, 0));
	m_pStatus->AddProgressBar("Image/UI/townscene/bar_status/mana.png", D3DXVECTOR3(148, 61, 0));
	m_pStatus->AddProgressBar("Image/UI/townscene/bar_status/exp.png", D3DXVECTOR3(153, 76, 0));
	m_pStatus->SetScaleOutline(1.0f);
	m_pStatus->SetHidden(false);
	// << 

	// >> ���� ���� â
	m_pTrooptype = new cUIMiniMap();
	m_pTrooptype->Setup(D3DXVECTOR3(WND_WIDTH * 0.2f, WND_HEIGHT * 0.05f, 0), UI_MINIMAP);
	m_pTrooptype->Setup_Image("image/UI/townscene/trooptype/bg.png", 150);
	m_pTrooptype->Setup_exitbtn(D3DXVECTOR3(740, 0, 0),
		"image/ui/townscene/trooptype/btn_idle.png", "image/ui/townscene/trooptype/btn_mouseover.png", "image/ui/townscene/trooptype/btn_select.png");
	m_pTrooptype->SetEventID(TOWN_MINIMAP_TROOPTYPE);

	/// ���� ���� ��ư : �и�
	cUIButton* pBtn_Battle_Melee = new cUIButton;
	pBtn_Battle_Melee->Setup(D3DXVECTOR3(52, 93, 0), UI_BUTTON);
	pBtn_Battle_Melee->Setup_Button("Image/UI/townscene/trooptype/btn_melee_idle.png",
		"Image/UI/townscene/trooptype/btn_melee_mouseover.png",
		"Image/UI/townscene/trooptype/btn_melee_selected.png", TOWN_BTN_MELEE);
	m_vecEventBtn.push_back(pBtn_Battle_Melee);
	m_pTrooptype->AddChild(pBtn_Battle_Melee);
	
	/// ���� ���� ��ư : ����
	cUIButton* pBtn_Battle_Bow = new cUIButton;
	pBtn_Battle_Bow->Setup(D3DXVECTOR3(280, 93, 0), UI_BUTTON);
	pBtn_Battle_Bow->Setup_Button("Image/UI/townscene/trooptype/btn_bow_idle.png",
		"Image/UI/townscene/trooptype/btn_bow_mouseover.png",
		"Image/UI/townscene/trooptype/btn_bow_selected.png", TOWN_BTN_BOW);
	m_vecEventBtn.push_back(pBtn_Battle_Bow);
	m_pTrooptype->AddChild(pBtn_Battle_Bow);
	
	/// ���� ���� ��ư : ī�߸�
	cUIButton* pBtn_Battle_Carvaly = new cUIButton;
	pBtn_Battle_Carvaly->Setup(D3DXVECTOR3(508, 93, 0), UI_BUTTON);
	pBtn_Battle_Carvaly->Setup_Button("Image/UI/townscene/trooptype/btn_carvaly_idle.png",
		"Image/UI/townscene/trooptype/btn_carvaly_mouseover.png",
		"Image/UI/townscene/trooptype/btn_carvaly_selected.png", TOWN_BTN_CARVALY);
	m_vecEventBtn.push_back(pBtn_Battle_Carvaly);
	m_pTrooptype->AddChild(pBtn_Battle_Carvaly);

	// <<

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
	m_vecMsg.push_back(pMsgBox_Human);

	// �޸� ���� â
	cUIMsgBox* pMsgBox_Orc = new cUIMsgBox;
	pMsgBox_Orc->Setup(D3DXVECTOR3(930, 50, 0), UI_MSGBOX);
	pMsgBox_Orc->Setup_MsgBox("image/ui/selectscene/msgbox_orc/msgbox_orc_bg.png", D3DXVECTOR3(50, 50, 0), ST_SIZEN(250, 500), SELECT_MSGBOX_HUMAN, FONT_SHOP);
	m_vecMsg.push_back(pMsgBox_Orc);
}

void cUIManager::Setup_BattleScene_Orc()
{
	// >> ü�� ���� ǥ�� ����
	m_pStatus = new cUIProgressBar;
	m_pStatus->Setup(D3DXVECTOR3(0, 0, 0.0f), UI_PROGRESSBAR);
	if (OBJECT->GetPlayerID() == C_C_HUMAN_MALE) m_pStatus->Setup_Progress("Image/UI/townscene/bar_status/status_human.png", "", D3DXVECTOR3(30, 20, 0));
	else if (OBJECT->GetPlayerID() == C_C_ORC_MALE) m_pStatus->Setup_Progress("Image/UI/townscene/bar_status/status_orc.png", "", D3DXVECTOR3(30, 20, 0));
	m_pStatus->AddProgressBar("Image/UI/townscene/bar_status/life.png", D3DXVECTOR3(148, 33, 0));
	m_pStatus->AddProgressBar("Image/UI/townscene/bar_status/mana.png", D3DXVECTOR3(148, 61, 0));
	m_pStatus->AddProgressBar("Image/UI/townscene/bar_status/exp.png", D3DXVECTOR3(153, 76, 0));
	m_pStatus->SetScaleOutline(1.0f);
	m_pStatus->SetHidden(false);
	// << 

	// �̴ϸ�
	m_pMiniMap = new cUIMiniMap;
	m_pMiniMap->Setup(D3DXVECTOR3(WND_WIDTH * 0.25f, WND_HEIGHT * 0.10f, 0), UI_MINIMAP);
	m_pMiniMap->Setup_Image("image/UI/BattleScene_Orc/minimap/minimap.png", 150);
	m_pMiniMap->Setup_exitbtn(D3DXVECTOR3(674, 0, 0),
		"image/ui/BattleScene_Orc/minimap/btn_idle.png", "image/ui/BattleScene_Orc/minimap/btn_mouseover.png", "image/ui/BattleScene_Orc/minimap/btn_select.png");
	m_pMiniMap->Setup_BG(D3DXVECTOR3(140, 100, 0), "image/ui/BattleScene_Human/minimap/BG.png");
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

	// >> Ȱ �� �� ���� ��ǥ��
	m_pAim = new cUIImage();
	m_pAim->Setup(D3DXVECTOR3(WND_WIDTH * 0.5f, WND_HEIGHT * 0.5f, 0), UI_IMAGE);
	m_pAim->Setup_Image("image/UI/townscene/aim/aim.png");
	m_pAim->SetHidden(false);
	// <<
}

void cUIManager::Setup_BattleScene_Human()
{
	// >> ü�� ���� ǥ�� ����
	m_pStatus = new cUIProgressBar;
	m_pStatus->Setup(D3DXVECTOR3(0, 0, 0.0f), UI_PROGRESSBAR);
	if (OBJECT->GetPlayerID() == C_C_HUMAN_MALE) m_pStatus->Setup_Progress("Image/UI/townscene/bar_status/status_human.png", "", D3DXVECTOR3(30, 20, 0));
	else if (OBJECT->GetPlayerID() == C_C_ORC_MALE) m_pStatus->Setup_Progress("Image/UI/townscene/bar_status/status_orc.png", "", D3DXVECTOR3(30, 20, 0));
	m_pStatus->AddProgressBar("Image/UI/townscene/bar_status/life.png", D3DXVECTOR3(148, 33, 0));
	m_pStatus->AddProgressBar("Image/UI/townscene/bar_status/mana.png", D3DXVECTOR3(148, 61, 0));
	m_pStatus->AddProgressBar("Image/UI/townscene/bar_status/exp.png", D3DXVECTOR3(153, 76, 0));
	m_pStatus->SetScaleOutline(1.0f);
	m_pStatus->SetHidden(false);

	// << 
	// �̴ϸ�
	m_pMiniMap = new cUIMiniMap;
	m_pMiniMap->Setup(D3DXVECTOR3(WND_WIDTH * 0.25f, WND_HEIGHT * 0.10f, 0), UI_MINIMAP);
	m_pMiniMap->Setup_Image("image/UI/BattleScene_Human/minimap/ground3.png", 150);
	m_pMiniMap->Setup_exitbtn(D3DXVECTOR3(674, 0, 0),
		"image/ui/BattleScene_Human/minimap/btn_idle.png", "image/ui/BattleScene_Human/minimap/btn_mouseover.png", "image/ui/BattleScene_Human/minimap/btn_select.png");
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

	// >> Ȱ �� �� ���� ��ǥ��
	m_pAim = new cUIImage();
	m_pAim->Setup(D3DXVECTOR3(WND_WIDTH * 0.5f, WND_HEIGHT * 0.5f, 0), UI_IMAGE);
	m_pAim->Setup_Image("image/UI/townscene/aim/aim.png");
	m_pAim->SetHidden(false);
	// <<
}

void cUIManager::Setup()
{
	m_pMiniMap = NULL;
	m_pInven = NULL;
	m_pStatus = NULL;
	m_pTrooptype = NULL;
	m_pResultMessage = NULL;
	m_pAim = NULL;
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
	SAFE_DELETE(m_pAim);
	SAFE_DELETE(m_pStatus);
	SAFE_DELETE(m_pTrooptype);
	SAFE_DELETE(m_pResultMessage);
}

void cUIManager::Update(float deltaTime)
{
	if (m_pResultMessage) m_pResultMessage->Update(deltaTime);

	if (m_pStatus) m_pStatus->ResetBarLength(0, OBJECT->GetPlayerHPRate());

	PressKey();
	Update_ConnectedUI();

	if (m_pTrooptype) m_pTrooptype->Update(deltaTime);

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

	if (m_pInven) m_pInven->Update(deltaTime);
}

void cUIManager::Render(LPD3DXSPRITE pSprite)
{
	if(m_pStatus) m_pStatus->Render(pSprite);

	for (int i = 0; i < m_vecTab.size(); i++)
	{
		m_vecTab[i]->Render(pSprite);
	}

	for (int i = 0; i < m_vecMsg.size(); i++)
	{
		m_vecMsg[i]->Render(pSprite);
	}

	if (m_pInven) m_pInven->Render(pSprite);

	if (m_pMiniMap) m_pMiniMap->Render(pSprite);

	if (m_pTrooptype) m_pTrooptype->Render(pSprite);

	for (int i = 0; i < m_vecShownBtn.size(); i++)
	{
		m_vecShownBtn[i]->Render(pSprite);
	}

	if (m_pResultMessage) m_pResultMessage->Render(pSprite);
}

// �� ���濡 ���� UI ��ü �����Ű�� �Լ�
void cUIManager::Change(int sceneID)
{
	Release();

	switch (sceneID)
	{
	case SCENE_LOGIN:
		Setup_LoginScene();
		break;
	case SCENE_SELECT:
		Setup_SelectScene();
		break;
	case SCENE_TOWN_HUMAN:
		Setup_TownScene();
		break;
	case SCENE_TOWN_ORC:
		Setup_TownScene();
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
	// ���忡�� �̴ϸ� ����
	if (INPUT->IsKeyDown(VK_TAB) && m_pMiniMap)
	{
		int sceneTag = SCENE->GetCurrentSceneTag();
		if (sceneTag < SCENE_BATTLE_HUMAN || sceneTag > SCENE_BATTLE_ORC) return;		// ���� �� �ƴϸ� �̴ϸ� ���������� ����ó��
		m_pMiniMap->SetHiddenAll(!(m_pMiniMap->GetHidden()));
	}

	// ������â ����
	if (INPUT->IsKeyDown(VK_I))
	{
		if (m_vecTab.size() < 4) return;	// ������â ���� �ȵǾ����� ��� ����ó��
		if (!m_vecTab[0]->GetHidden()) return;	// ����â �������� �κ��丮 �ȶߵ��� ����ó��

		bool hidden = !m_vecTab[3]->GetHidden();
		m_vecTab[3]->SetHidden(hidden);
		AddItem_Tab(TOWN_TAB_INVENTORY_EQUIP);
		m_vecTab[3]->SetDef();

		m_pInven->SetHiddenAll(hidden);
	}
}

void cUIManager::Update_ConnectedUI()
{
	// >> �������� ����â�� ���ų� ������â�� ���� ����â�� ������â�� ��� �������� �κ�
	if (m_vecTab.size() >= 3 && m_vecTab[1]->GetHidden() && m_vecTab[2]->GetHidden()) m_vecTab[0]->SetHiddenAll(true);
	if (m_vecTab.size() >= 3 && m_vecTab[0]->GetHidden())
	{
		m_vecTab[1]->SetHiddenAll(true);
		m_vecTab[2]->SetHiddenAll(true);
	}
	// << 

	// >> �κ��丮 ���� ������â ���� �κ�
	if (m_vecTab.size() >= 4 && m_vecTab[3]->GetHidden()) m_pInven->SetHiddenAll(true);
	if (m_vecTab.size() >= 4 && m_pInven->GetHidden()) m_vecTab[3]->SetHiddenAll(true);
	// << 
}

void cUIManager::SetEvent(int uiID, int order)
{
	// 0 : �� ������ �����Ǹ�â,
	// 1 : ������� â
	// 2 : ������ â
	// 3 : �� ������ â
	// 4 : ¡���� â
	switch (uiID)
	{
	case TOWN_TAB_SHOP_ATT:
	{
		bool bOrder = order;
		m_vecTab[2]->SetHidden(!bOrder);
		m_vecTab[4]->SetHidden(!bOrder);
		m_vecTab[0]->SetHidden(bOrder);
		m_vecTab[0]->SetDef();
		m_vecTab[1]->SetHidden(bOrder);
		m_vecTab[1]->SetDef();
	}
		break;
	case TOWN_TAB_SHOP_DEF:
	{
		bool bOrder = order;
		m_vecTab[1]->SetHidden(!bOrder);
		m_vecTab[4]->SetHidden(!bOrder);
		m_vecTab[0]->SetHidden(bOrder);
		m_vecTab[0]->SetDef();
		m_vecTab[2]->SetHidden(bOrder);
		m_vecTab[2]->SetDef();
	}
		break;
	case TOWN_TAB_RECRUIT:
	{
		bool bOrder = order;
		m_vecTab[1]->SetHidden(!bOrder);
		m_vecTab[2]->SetHidden(!bOrder);
		m_vecTab[0]->SetHidden(!bOrder);
		m_vecTab[4]->SetHidden(bOrder);
		m_vecTab[4]->SetDef();
	}
	break;
	case TOWN_MINIMAP:
	{
		bool bOrder = order;
		if (m_pMiniMap) m_pMiniMap->SetHiddenAll(bOrder);
		for (int i = 0; i < m_vecTab.size(); i++)
		{
			m_vecTab[i]->SetHidden(!bOrder);
		}
	}
		break;
	case SELECT_MSGBOX_ORC:
		m_vecMsg[0]->SetHidden(order);
		break;
	case SELECT_MSGBOX_HUMAN:
		m_vecMsg[1]->SetHidden(order);
		break;
	case TOWN_MINIMAP_TROOPTYPE:
		if(m_pTrooptype) m_pTrooptype->SetHiddenAll(order);
		if (m_pMiniMap)
		{
			m_pMiniMap->Update(0);
			m_pMiniMap->SetHiddenAll(!order);
		}
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

	// ���â���� Ŭ���� ���� ������ ���̵� ��ȯ�ϴ� �κ�
	if(m_pInven && itemID == -1) m_pInven->GetClickedItemID(eventID, itemID);
}

void cUIManager::AddItem_Tab(int tabID)
{
	int index = -1;
	switch (tabID)
	{
	case TOWN_TAB_INVENTORY:
		index = 0;
		break;
	case TOWN_TAB_INVENTORY_EQUIP:
		index = 3;
		break;
	}

	// �ش� �κ��丮�� ���� ��� ����ó��
	if (index == -1) return;			

	// ��_�κ��丮 �ʱ�ȭ
	m_vecTab[index]->ClearShownData();
	// ��_�κ��丮 ���� �����
	vector<int> vecInven = OBJECT->GetInventory();
	for (int i = 0; i < vecInven.size(); i++)
	{
		ST_ITEM* item = ITEMDB->GetItem(vecInven[i]);
		m_vecTab[index]->AddSlotData(I_M_INVENTORY, item->eSmallID, item->name, item->szImagePath, item->info, item->cost);
	}
	m_vecTab[index]->SetDef();
}

void cUIManager::ResetEquipment(vector<int> vecEquipment)
{
	m_pInven->ResetItems(vecEquipment);
}

void cUIManager::DrawAim(LPD3DXSPRITE pSprite)
{
	m_pAim->Update(0);
	m_pAim->Render(pSprite);
}

void cUIManager::CreateResultMessage(int resultID)
{
	m_pResultMessage = new cUIMiniMap;
	m_pResultMessage->Setup(D3DXVECTOR3(0,0, 0), UI_MINIMAP);
	
	if (resultID == BATTLE_MINIMAP_VICTORY)
		m_pResultMessage->Setup_Image("Image/UI/battlescene_human/resultmessage/victory.png", 150);
	else if (resultID == BATTLE_MINIMAP_DEFEAT)
		m_pResultMessage->Setup_Image("Image/UI/battlescene_human/resultmessage/defeat.png", 150);

	// �̴ϸʹ�ư 1
	cUIButton* pBnt_Exit = new cUIButton;
	pBnt_Exit->Setup(D3DXVECTOR3(500, 355, 0), UI_BUTTON);
	pBnt_Exit->Setup_Button("Image/UI/battlescene_human/resultmessage/btn_idle.png",
		"Image/UI/battlescene_human/resultmessage/btn_mouseover.png",
		"Image/UI/battlescene_human/resultmessage/btn_select.png", BATTLE_MINIMAP_RESULT);
	m_vecEventBtn.push_back(pBnt_Exit);
	m_pResultMessage->AddChild(pBnt_Exit);
	m_pResultMessage->SetHiddenAll(false);
}