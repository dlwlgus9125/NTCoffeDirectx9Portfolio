#include "stdafx.h"
#include "cItemDB.h"

void cItemDB::Setup()
{
	/*Add(new ST_Character(C_R_END, C_G_END, C_C_SWORD_SWORD, 100.0f, 100.f, 100.0f, 4, "Character/Weapon/", "Weapon_Sword1.x", "Weapon_Attack_Bone_Col_root"));
	Add(new ST_Character(C_R_END, C_G_END, C_C_SHIELD_SHIELD, 100.0f, 100.f, 100.0f, 4, "Character/Weapon/", "Sheild_Blood1.x", "Weapon_Attack_Bone_Col_root"));*/
	Add(new ST_ITEM(I_L_MELEE, I_M_SWORD, I_S_SHORTSWORD, "�� �ҵ�", "���� ���� ª�� ���̴�.", 50, "image/item/sword/shortsword.png"," "," "));
	Add(new ST_ITEM(I_L_MELEE, I_M_SWORD, I_S_LONGSWORD, "�� �ҵ�", "����� �� ���̴�.", 250, "image/item/sword/longsword.png", " ", " "));

	//>>���� ���� ������ ����
	Add(new ST_ITEM(I_L_MELEE, I_M_SWORD, I_S_BASTARDSWORD, "�ٽ�Ÿ�� �ҵ�", "�߼� �糯 ���̴�.", 750, "image/item/sword/bastardsword.png", "Character/Weapon/", "Weapon_Sword1.x", TEXTURE->GetCharacterResource("Character/Weapon/", "Weapon_Sword1.x")));
	Add(new ST_ITEM(I_L_MELEE, I_M_SHEILD, I_S_SHEILD, "ī��Ʈ ����", "�߼� ��� �����̴�.", 750, "image/item/sword/bastardsword.png", "Character/Weapon/", "Sheild_Blood1.x", TEXTURE->GetCharacterResource("Character/Weapon/", "Sheild_Blood1.x")));
	
	
	Add(new ST_ITEM(I_L_MELEE, I_M_AXE, I_S_SMALLAXE, "ª�� ����", "�ο�⿣ ª�� ����.", 50, "image/item/axe/ShortAxe.png", " ", " "));
	Add(new ST_ITEM(I_L_MELEE, I_M_AXE, I_S_WARAXE, "���� ����", "��� �� ������ ����.", 250, "image/item/axe/WarAxe.png", " ", " "));
	Add(new ST_ITEM(I_L_MELEE, I_M_AXE, I_S_TWOHANDAXE, "�糯 ����", "�糯�� �ο�� ���� ����.", 750, "image/item/axe/TH_axe.png", " ", " "));
}

void cItemDB::Add(ST_ITEM * pData)
{
	if (m_mapObject.find(pData->eSmallID) == m_mapObject.end())
	{
		m_mapObject[pData->eSmallID] = pData;
	}
}

void cItemDB::Destroy()
{
	for each(auto it in m_mapObject)
	{
		SAFE_DELETE(it.second);
	}

	delete this;
}