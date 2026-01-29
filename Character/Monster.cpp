#include <string>
#include "Monster.h"

AMonster::AMonster(const string& Name, const FUnitStat& Stat)
    : ACharacter(Name, Stat)
{
    cout << "[Monster 생성] " << Name << endl;
}

void AMonster::Attack(ACharacter* Target)
{
    cout << Name << "이(가) 나의 용사(을)를 공격합니다" << endl;
    ACharacter::Attack(Target);
}

