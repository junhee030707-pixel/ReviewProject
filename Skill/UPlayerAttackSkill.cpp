#include "UPlayerAttackSkill.h"
#include "../Character/Character.h" // 전 폴더로 돌아감(부모폴더로) ../
#include <iostream>

UPlayerAttackSkill::UPlayerAttackSkill(ACharacter* Owner)
    : USkill(Owner)
{
}

void UPlayerAttackSkill::Play(ACharacter* Target)
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
    if (result.bCritical == false)
    {
        AttackMessage = "대검으로 평타를 칩니다";
    }
    result.PrintMessage("일반공격 실시!");

}

