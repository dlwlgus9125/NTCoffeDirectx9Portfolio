#include "stdafx.h"
#include "Bow_State.h"


void Bow_Death::OnBegin(cBowUnit * pUnit)
{
	pUnit->GetMesh()->SetAnimationIndexBlend(B_DEATH);
	pUnit->GetCharacterEntity()->SetDeath(true);
}

void Bow_Death::OnUpdate(cBowUnit * pUnit, float deltaTime)
{
	if (pUnit->IsDeath() == false && pUnit->GetMesh()->GetPassedTime() > pUnit->GetMesh()->GetCurrentAnim()->GetPeriod() - 0.3f)
	{
		pUnit->SetDeath(true);
	}
}

void Bow_Death::OnEnd(cBowUnit * pUnit)
{
}
