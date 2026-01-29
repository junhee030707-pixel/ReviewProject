#include <string>
#include "Monster.h"

AMonster::AMonster(const string& Name, const FUnitStat& Stat)
    : ACharacter(Name, Stat)
{
    cout << "[Monster 생성] " << Name << endl;
}

void AMonster::Attack(ACharacter* Target)
{
    cout <<  Name << "이 공격합니다" << endl;
    Target->TakeDamage(Stat.Atk);
}

