#include <string>
#include "Monster.h"

AMonster::AMonster(const string& Name, const FUnitStat& Stat)
    : ACharacter(Name, Stat)
{
    cout << "[Monster 생성] " << Name << endl;
}

FDamageResult AMonster::Attack(ACharacter* Target)
{
    FDamageResult result = ACharacter::Attack(Target);
    if (result.bCritical) 
    {
        cout << "(이)가 크아아앙(크리티컬 공격) 을(를) 나의 용사에게 입힙니다! " << endl;
    }

    cout << Name << "이(가) 나의 용사(을)를 공격합니다." << " 데미지:" << result.Damage << endl;
    cout << Target->GetName() << "HP:" << Target->GetHp() << endl;
    return result;
   
}

void AMonster::UseSkill(ACharacter* Target)
{
    Stat.Mp -= 10;

    int ActualDamage = Target->TakeDamage(Stat.Atk * 2);
    FDamageResult Result;
    Result.Attacker = this;
    Result.Target = Target;
    Result.bCritical = false;
    Result.Damage = ActualDamage;
    Result.PrintMessage("스킬발동: 파이얼 인더 헐...!");
}

