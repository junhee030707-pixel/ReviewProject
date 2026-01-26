#include <iostream>
#include <Windows.h>
#include <ctime>
#include "Character/Character.h"
#include "Character/Monster.h"
#include "Character/Player.h"

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    FUnitStat PlayerStat{ 200, 15, 10, 10 };
    FUnitStat MonsterStat{ 100, 10, 5, 10 };

    //객채는 플레이어, 몬스터지만 :: 부모클래스ACharacter의 포인터로 사용한다.
    ACharacter* Player = new APlayer("나의 용사", PlayerStat);
    ACharacter* Monster = new AMonster("무서운 오크", MonsterStat);

    cout << "===  데스매치 시작!  ===" << endl;
    Sleep(1000);

    while (!Player->IsDead() && !Monster->IsDead())
    {
        Player->Attack(Monster);

        if (Monster->IsDead())
        {
            cout << "몬스터가 쓰러졌습니다! 승리!" << endl;
            break;
        }

        Sleep(500);

        Monster->Attack(Player);
        if (Player->IsDead())
        {
            cout << "플레이어가 쓰러졌습니다... 패배..." << endl;
            break;
        }

        Sleep(1000);
    }

    delete Player;
    delete Monster;
    return 0;
}
