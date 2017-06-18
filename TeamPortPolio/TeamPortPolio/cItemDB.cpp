#include "stdafx.h"
#include "cItemDB.h"

void cItemDB::Setup()
{
	Add(new ST_ITEM(I_L_MELEE, I_M_SWORD, I_S_SHORTSWORD, "�� �ҵ�", "���� ���� ª�� ���̴�.", 50, "image/item/sword/shortsword.png"));
	Add(new ST_ITEM(I_L_MELEE, I_M_SWORD, I_S_LONGSWORD, "�� �ҵ�", "����� �� ���̴�.", 250, "image/item/sword/longsword.png"));
	Add(new ST_ITEM(I_L_MELEE, I_M_SWORD, I_S_BASTARDSWORD, "�ٽ�Ÿ�� �ҵ�", "�߼� �糯 ���̴�.", 750, "image/item/sword/bastardsword.png"));
	Add(new ST_ITEM(I_L_MELEE, I_M_AXE, I_S_SMALLAXE, "ª�� ����", "�ο�⿣ ª�� ����.", 50, "image/item/axe/ShortAxe.png"));
	Add(new ST_ITEM(I_L_MELEE, I_M_AXE, I_S_WARAXE, "���� ����", "��� �� ������ ����.", 250, "image/item/axe/WarAxe.png"));
	Add(new ST_ITEM(I_L_MELEE, I_M_AXE, I_S_TWOHANDAXE, "�糯 ����", "�糯�� �ο�� ���� ����.", 750, "image/item/axe/TH_axe.png"));
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