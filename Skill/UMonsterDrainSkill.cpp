#include "UMonsterDrainSkill.h"
#include "../Character/Character.h" // 전 폴더로 돌아감(부모폴더로) ../
#include <iostream>

UMonsterDrainSkill::UMonsterDrainSkill(ACharacter* Owner)
    : USkill(Owner)
{
}

void UMonsterDrainSkill::Play(ACharacter* Target)
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
        AttackMessage = "무서운 오크 (이)가 이빨로 깨뭅니다 앙!";
    }
    result.PrintMessage("스킬 : 깨물어 앙탈부리기");

}