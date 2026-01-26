#include <string>
#include "Monster.h"

AMonster::AMonster(const string& Name, const FUnitStat& Stat)
    : ACharacter(Name, Stat)
{
    cout << "[Monster 생성] " << Name << endl;
}
