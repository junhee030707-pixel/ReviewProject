#include <iostream>
#include <Windows.h>
#include <ctime>
#include "Character/Character.h"
#include "Character/Monster.h"
#include "Character/Player.h"

void  WaitForPlayerInput()
{
    system("pause");
    cout << endl;
}

bool BattleTurn(ACharacter* Attacker, ACharacter* Defender)
{
    Attacker->DoAction(Defender);
    WaitForPlayerInput();

    while (Defender->IsDead()) 
    {
        return true;
    }
    return false;
}
int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    //객채는 플레이어, 몬스터지만 :: 부모클래스ACharacter의 포인터로 사용한다.
    ACharacter* Player = new APlayer("나의 용사", FUnitStat(200, 10, 30, 5, 10));
    ACharacter* Monster = new AMonster("무서운 오크", FUnitStat(100, 10, 20, 3, 10));

    cout << "===  데스매치 시작!  ===" << endl;
    WaitForPlayerInput();

    while (true)
    {
        // 1. 플레이어의 턴 (게임 끝났으면 break)
        if (BattleTurn(Player, Monster) == true)
        {
            break;
        }

        // 2. 몬스터의 턴 (게임 끝났으면 break)
        if (BattleTurn(Monster, Player) == true)
        {
            break;
        }
    }

    delete Player;
    delete Monster;

    WaitForPlayerInput();
    return 0;
}
