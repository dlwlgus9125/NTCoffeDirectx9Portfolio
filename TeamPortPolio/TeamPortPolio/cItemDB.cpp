#include "stdafx.h"
#include "cItemDB.h"

void cItemDB::Setup()
{
	//Add(new ST_ITEM(I_L_MELEE, I_M_SWORD, I_S_SHORTSWORD, "�� �ҵ�", "���� ���� ª�� ���̴�.", 50, "image/item/sword/shortsword.png"));
	//Add(new ST_ITEM(I_L_MELEE, I_M_SWORD, I_S_LONGSWORD, "�� �ҵ�", "����� �� ���̴�.", 250, "image/item/sword/longsword.png"));
	//Add(new ST_ITEM(I_L_MELEE, I_M_SWORD, I_S_BASTARDSWORD, "�ٽ�Ÿ�� �ҵ�", "�߼� �糯 ���̴�.", 750, "image/item/sword/bastardsword.png"));
	//Add(new ST_ITEM(I_L_MELEE, I_M_AXE, I_S_SMALLAXE, "ª�� ����", "�ο�⿣ ª�� ����.", 50, "image/item/axe/ShortAxe.png"));
	//Add(new ST_ITEM(I_L_MELEE, I_M_AXE, I_S_WARAXE, "���� ����", "��� �� ������ ����.", 250, "image/item/axe/WarAxe.png"));
	//Add(new ST_ITEM(I_L_MELEE, I_M_AXE, I_S_TWOHANDAXE, "�糯 ����", "�糯�� �ο�� ���� ����.", 750, "image/item/axe/TH_axe.png"));
	Add(new ST_ITEM(I_L_MELEE, I_M_SWORD,I_S_SWORD_SHORT_NOR, "�ܰ�", "����� �ܰ�", 100, "image/item/sword/sword1.png", "Character/Weapon/", "Weapon_Sword1.x", "Weapon_Attack_Bone_Col_root"));
	Add(new ST_ITEM(I_L_MELEE, I_M_SWORD,I_S_SWORD_SHORT_ECH,"��ȭ�� �ܰ�","���� ������ �ܰ�", 250, "image/item/sword/sword1_2.png", "Character/Weapon/", "Weapon_Sword1.x", "Weapon_Attack_Bone_Col_root"));
	Add(new ST_ITEM(I_L_MELEE, I_M_SWORD,I_S_SWORD_SHORT_GLZ,"������ �ܰ�","�� �������� �ܰ�", 400, "image/item/sword/sword1_3.png", "Character/Weapon/", "Weapon_Sword1.x", "Weapon_Attack_Bone_Col_root"));
	Add(new ST_ITEM(I_L_MELEE, I_M_SWORD,I_S_SWORD_LONG_NOR,"���", "����ϰ� �� ��", 500, "image/item/sword/sword2.png", "Character/Weapon/", "Weapon_Sword1.x", "Weapon_Attack_Bone_Col_root"));
	Add(new ST_ITEM(I_L_MELEE, I_M_SWORD,I_S_SWORD_LONG_ECH, "��ȭ�� ���", "��ȭ�Ǿ� �ο�� ���� ���", 700, "image/item/sword/sword2_2.png", "Character/Weapon/", "Weapon_Sword1.x", "Weapon_Attack_Bone_Col_root"));
	Add(new ST_ITEM(I_L_MELEE, I_M_SWORD,I_S_SWORD_MITHRIL_NOR,"�̽�����", "�Ǵ볪�� �̽��� ��", 1000, "image/item/sword/sword3.png", "Character/Weapon/", "Weapon_Sword1.x", "Weapon_Attack_Bone_Col_root"));
	Add(new ST_ITEM(I_L_MELEE, I_M_SWORD,I_S_SWORD_MITHRIL_ECH,"��ȭ�� �̽�����", "�Ǵ볪�� �� �̽�����", 1500, "image/item/sword/sword3_2.png", "Character/Weapon/", "Weapon_Sword1.x", "Weapon_Attack_Bone_Col_root"));
	Add(new ST_ITEM(I_L_MELEE, I_M_SWORD,I_S_SWORD_MITHRIL_GLZ,"������ �̽�����", "������ ������ �Ӵ� �̽�����", 2000, "image/item/sword/sword3_3.png", "Character/Weapon/", "Weapon_Sword1.x", "Weapon_Attack_Bone_Col_root"));
	Add(new ST_ITEM(I_L_MELEE, I_M_AXE, I_S_AXE_STONE,"�� ����", "������ �ô� �������� ����", 90, "image/item/axe/axe1.png", "Character/Weapon/", "WeaponAxe.x", "Weapon_Attack_Bone_Col_root"));
	Add(new ST_ITEM(I_L_MELEE, I_M_AXE, I_S_AXE_IRON_NOR, "ö ����", "���� �ż��� �ô뿡 �߳����� ����", 400,"image/item/axe/axe2.png", "Character/Weapon/", "WeaponAxe.x", "Weapon_Attack_Bone_Col_root"));
	Add(new ST_ITEM(I_L_MELEE, I_M_AXE, I_S_AXE_IRON_HQ, "��ȭ�� ö����", "��ȭ�Ǿ� �ε�� �б� ���� ����", 500, "image/item/axe/axe2_2.png", "Character/Weapon/", "WeaponAxe.x", "Weapon_Attack_Bone_Col_root"));
	Add(new ST_ITEM(I_L_MELEE, I_M_AXE, I_S_AXE_MITHRIL_NOR,"�̽��� ����","�̽����� ���� �ο�� ���� ����", 1000, "image/item/axe/axe3.png", "Character/Weapon/", "WeaponAxe.x", "Weapon_Attack_Bone_Col_root"));
	Add(new ST_ITEM(I_L_MELEE, I_M_AXE, I_S_AXE_MITHRIL_HQ, "��ȭ�� �̽��� ����", "��ȭ�Ǿ� �θ� ������ ���� ����", 1500, "image/item/axe/axe3_2.png", "Character/Weapon/", "WeaponAxe.x", "Weapon_Attack_Bone_Col_root"));
	Add(new ST_ITEM(I_L_MELEE, I_M_AXE, I_S_AXE_HAND_RUST,"�� �ٷ� �յ���","�� �� ���� ����", 200, "image/item/axe/axe4.png", "Character/Weapon/", "WeaponAxe.x", "Weapon_Attack_Bone_Col_root"));
	Add(new ST_ITEM(I_L_MELEE, I_M_AXE, I_S_AXE_HAND_HQ,"������ �յ���","�� �ν����� �׷��� �յ���", 300, "image/item/axe/axe4_1.png", "Character/Weapon/", "WeaponAxe.x", "Weapon_Attack_Bone_Col_root"));
	Add(new ST_ITEM(I_L_MELEE, I_M_AXE, I_S_AXE_HONORABLE,"���ο� �յ���","������ ��� ���� ��� ����", 700, "image/item/axe/axe4_2.png", "Character/Weapon/", "WeaponAxe.x", "Weapon_Attack_Bone_Col_root"));
	Add(new ST_ITEM(I_L_RANGE, I_M_BOW, I_S_BOW_WOODEN_NOR,"���� Ȱ","������ Ȱ", 100 , "image/item/bow/bow1.png", "Character/Weapon/", "WeaponBow.x", "Weapon_Attack_Bone_Col_root"));
	Add(new ST_ITEM(I_L_RANGE, I_M_BOW, I_S_BOW_WOODEN_ECH,"��ȭ�� ���� Ȱ","��Ÿ� �������� ���� Ȱ", 200, "image/item/bow/bow2.png", "Character/Weapon/", "WeaponBow.x", "Weapon_Attack_Bone_Col_root"));
	Add(new ST_ITEM(I_L_RANGE, I_M_BOW, I_S_BOW_WOODEN_GLZ,"������ ���� Ȱ","���鿡�� �ڶ��ϱ� ���� Ȱ", 350, "image/item/bow/bow2_2.png", "Character/Weapon/", "WeaponBow.x", "Weapon_Attack_Bone_Col_root"));
	Add(new ST_ITEM(I_L_RANGE, I_M_BOW, I_S_BOW_HUNTER_NOR,"��ɲ��� Ȱ","�䳢 ��ɿ� ������ Ȱ", 500, "image/item/bow/bow3.png", "Character/Weapon/", "WeaponBow.x", "Weapon_Attack_Bone_Col_root"));
	Add(new ST_ITEM(I_L_RANGE, I_M_BOW, I_S_BOW_HUNTER_GLZ,"������ ��ɲ��� Ȱ", "����� ��⿡ ���� Ȱ", 700, "image/item/bow/bow3_2.png", "Character/Weapon/", "WeaponBow.x", "Weapon_Attack_Bone_Col_root"));
	Add(new ST_ITEM(I_L_RANGE, I_M_BOW, I_S_BOW_ELF_NOR,"�������� Ȱ","������ �ָ��� �����ϱ� ���� Ȱ", 1100, "image/item/bow/bow4.png", "Character/Weapon/", "WeaponBow.x", "Weapon_Attack_Bone_Col_root"));
	Add(new ST_ITEM(I_L_RANGE, I_M_BOW, I_S_BOW_ELF_ECH,"��ȭ�� �������� Ȱ","���б��� �վ���� Ȱ", 1350, "image/item/bow/bow4_2.png", "Character/Weapon/", "WeaponBow.x", "Weapon_Attack_Bone_Col_root"));
	Add(new ST_ITEM(I_L_RANGE, I_M_BOW, I_S_BOW_ELF_GLZ,"������ ���������� Ȱ","������ ������ �մ� Ȱ", 1600, "image/item/bow/bow4_3.png", "Character/Weapon/", "WeaponBow.x", "Weapon_Attack_Bone_Col_root"));
	Add(new ST_ITEM(I_L_MELEE, I_M_ARMOR, I_S_ARMOR_OLD,"�㸧�� ����","�� �츸 �����ִ� ����", 150, "image/item/armor/chest1.png"));
	Add(new ST_ITEM(I_L_MELEE, I_M_ARMOR, I_S_ARMOR_PLATED,"���ݵ� ����","���ʰ��� ö�������� ���̴� ����", 400, "image/item/armor/chest1_2.png"));
	Add(new ST_ITEM(I_L_MELEE, I_M_ARMOR, I_S_ARMOR_MAGIC,"������ ����","30�� ����� ������ ��� ����", 650, "image/item/armor/chest1_3.png"));
	Add(new ST_ITEM(I_L_MELEE, I_M_ARMOR, I_S_ARMOR_DWARFMITHRIL,"������� �̽��� ����","����� ���׿��� ������ ����", 1000, "image/item/armor/chest1_4.png"));
	Add(new ST_ITEM(I_L_MELEE, I_M_ARMOR, I_S_ARMOR_SOLDEIER_RUST,"�� �ٷ� ���� ����","������ ���Ե� ����� ����", 1300, "image/item/armor/chest2.png"));
	Add(new ST_ITEM(I_L_MELEE, I_M_ARMOR, I_S_ARMOR_SOLDEIER_GLZ,"������ ���� ����","������ ���� �� ���۵� ����� ����", 1800, "image/item/armor/chest2_2.png"));
	Add(new ST_ITEM(I_L_MELEE, I_M_ARMOR, I_S_ARMOR_GENERAL_RUST,"�� �ٷ� �屺 ����","ưư������ ���� ���� ���� ����", 2500, "image/item/armor/chest3.png"));
	Add(new ST_ITEM(I_L_MELEE, I_M_ARMOR, I_S_ARMOR_GENERAL_GLZ,"�� ���� �屺 ����","õ�ϸ� ȣ���� �屺�� ���� ����", 4000, "image/item/armor/chest3_2.png"));
	Add(new ST_ITEM(I_L_MELEE, I_M_SHIELD, I_S_SHIELD_WOODEN_NOR,"���� ����","�Ʒÿ� ����", 100, "image/item/shield/shield1.png", "Character/Weapon/", "Sheild_Blood1.x", "Weapon_Attack_Bone_Col_root"));
	Add(new ST_ITEM(I_L_MELEE, I_M_SHIELD, I_S_SHIELD_WOODEN_IRONOVER,"ö ���� ���� ����","ö�� ����� �ܴ��� ����",250, "image/item/shield/shield1_2.png", "Character/Weapon/", "Sheild_Blood1.x", "Weapon_Attack_Bone_Col_root"));
	Add(new ST_ITEM(I_L_MELEE, I_M_SHIELD, I_S_SHIELD_WOODEN_ECH,"��ȭ�� ���� ����","����� �ָ��� ����� ����",400, "image/item/shield/shield1_3.png", "Character/Weapon/", "Sheild_Blood1.x", "Weapon_Attack_Bone_Col_root"));
	Add(new ST_ITEM(I_L_MELEE, I_M_SHIELD, I_S_SHIELD_WOODEN_GLZ,"������ ���� ����","������ ���� ����",700, "image/item/shield/shield1_4.png", "Character/Weapon/", "Sheild_Blood1.x", "Weapon_Attack_Bone_Col_root"));
	Add(new ST_ITEM(I_L_MELEE, I_M_SHIELD, I_S_SHIELD_IRON_NOR,"ö ����","������ �⺻ ����",1100, "image/item/shield/shield2.png", "Character/Weapon/", "Sheild_Blood1.x", "Weapon_Attack_Bone_Col_root"));
	Add(new ST_ITEM(I_L_MELEE, I_M_SHIELD, I_S_SHIELD_IRON_RUST,"�� �ٷ� ö ����","�� ���� ������ ���� ����", 1300, "image/item/shield/shield2_2.png", "Character/Weapon/", "Sheild_Blood1.x", "Weapon_Attack_Bone_Col_root"));
	Add(new ST_ITEM(I_L_MELEE, I_M_SHIELD, I_S_SHIELD_IRON_GLZ,"������ ö ����","���忡�� �����̴� ���� ����", 1600, "image/item/shield/shield2_3.png", "Character/Weapon/", "Sheild_Blood1.x", "Weapon_Attack_Bone_Col_root"));
	Add(new ST_ITEM(I_L_MELEE, I_M_SHIELD, I_S_SHIELD_HONORABLE,"���ο� ����","����� �屺�� ���� ����", 2200, "image/item/shield/shield3.png", "Character/Weapon/", "Sheild_Blood1.x", "Weapon_Attack_Bone_Col_root"));
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
	m_mapObject.clear();
	delete this;
}