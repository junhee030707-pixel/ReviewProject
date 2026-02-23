#include "UPlayerStrikeSkill.h"
#include "../Character/Character.h" // 전 폴더로 돌아감(부모폴더로) ../
#include <iostream>

UPlayerStrikeSkill::UPlayerStrikeSkill(ACharacter* Owner)
    : USkill(Owner)
{
}

void UPlayerStrikeSkill::Play(ACharacter* Target)
{
	int Damage = Owner->GetAtk();

	bool bCritical = (rand() % 100) < Owner->GetCritical();
    if (bCritical)
    {
        Damage = static_cast<int>(Damage * 1.5f);
    }

    int FinalDamage = Target->TakeDamage(Damage);
    FDamageResult result;
	result.Attacker = Owner;
	result.Target = Target;
    result.Damage = FinalDamage;
    result.bCritical = bCritical;

    std::string AttackMessage =
        "대검으로 공격합니다";
        if (result.bCritical)
        {
			AttackMessage = "(이)가 대검으로(크리티컬 공격) 을(를) 무서운 오크 에게 입힙니다!";
        }
    result.PrintMessage("스킬발동: 회심의 일격...!");
}
