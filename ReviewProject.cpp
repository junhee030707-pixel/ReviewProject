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
int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    //객채는 플레이어, 몬스터지만 :: 부모클래스ACharacter의 포인터로 사용한다.
    ACharacter* Player = new APlayer("나의 용사", FUnitStat(200, 50, 30, 5, 10));
    ACharacter* Monster = new AMonster("무서운 오크", FUnitStat(100, 30, 20, 3, 10));

    cout << "===  데스매치 시작!  ===" << endl;
    WaitForPlayerInput();

    while (!Player->IsDead() && !Monster->IsDead())
    {
        Player->Attack(Monster);

        if (Monster->IsDead())
        {
            cout << "몬스터가 쓰러졌습니다! 승리!" << endl;
            break;
        }
        WaitForPlayerInput();


        Monster->Attack(Player);
        if (Player->IsDead())
        {
            cout << "플레이어가 쓰러졌습니다... 패배..." << endl;
            break;
        }
        WaitForPlayerInput();

    }

    delete Player;
    delete Monster;

    WaitForPlayerInput();
    return 0;
}
