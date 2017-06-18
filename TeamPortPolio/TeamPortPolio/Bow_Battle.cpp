#include "stdafx.h"
#include "Bow_State.h"
#include "cBallisticArrow.h"

void Bow_Battle::OnBegin(cBowUnit * pUnit)
{
	pUnit->GetMesh()->SetAnimationIndexBlend(B_READYATTACK);
}

void Bow_Battle::OnUpdate(cBowUnit * pUnit, float deltaTime)
{
	
	if (pUnit->GetTargetObject() != NULL)
	{
		if (pUnit->GetMesh()->GetPassedTime() > pUnit->GetMesh()->GetCurrentAnim()->GetPeriod() - 0.3f)
		{
			switch (pUnit->GetMesh()->GetIndex())
			{
			case B_BOWATTACK1:
				pUnit->GetMesh()->SetAnimationIndexBlend(B_BOWATTACK2);
				//>>화살쏘는 생성자 넣을자리
				OBJECT->AddArrowByUnit(new cBallisticArrow(pUnit->GetCharacterEntity()->Pos(), pUnit->GetTargetObject()->GetCharacterEntity()->Pos(), 0.1f, D3DXVECTOR3(0, 0, 1), 0, 0), pUnit->GetCamp());
				//<<
				break;
			default:
				pUnit->GetMesh()->SetAnimationIndexBlend(B_BOWATTACK1);
				break;
			}
		}
	}
	else//거리로 계산해서 못쏘게 해야할 듯함
	{
		pUnit->GetMesh()->SetAnimationIndexBlend(B_READYATTACK);
	}
}

void Bow_Battle::OnEnd(cBowUnit * pUnit)
{
	pUnit->SetTargetObject(NULL);
}
