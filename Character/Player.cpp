#include <string>
#include "Player.h"

APlayer::APlayer(const string& Name, const FUnitStat& Stat)
    : ACharacter(Name, Stat), Level(1), Exp(0)
{
    cout << "[Player 생성] " << Name << " (Lv." << Level << ")" << endl;
}

void APlayer::LevelUp()
{
    
}

void APlayer::UseItem()
{
    
}

void APlayer::Attack(ACharacter* Target) 
{
        cout << Name << "이(가) 무서운오크(을)를 공격합니다" << endl;
        ACharacter::Attack(Target);
}

