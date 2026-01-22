#include <iostream>
#include <Windows.h>
#include <ctime>
#include "Character/Character.h"

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    // 1. 캐릭터 생성 (이름, 체력, 공격력 자유 설정)
    ACharacter* Player = new ACharacter("나의 용사", 200, 15, 10,  10.0f);
    ACharacter* Monster = new ACharacter("무서운 오크", 100, 10, 5, 10.0f);

    cout << "===  데스매치 시작!  ===" << endl;
    Sleep(1000);

    // 2. 무한 루프 (둘 다 살아있는 동안 반복)
    // 힌트: !Player->IsDead() 는 "플레이어가 죽지 않았다면" 이라는 뜻입니다.
    while (!Player->IsDead() && !Monster->IsDead())
    {
        // [플레이어 턴]
        // 1. 플레이어가 몬스터를 공격 (Attack 호출)
        // 1-1. Attack() 함수의 파라미터를 변경해주세요.
        // 1-2. Attack() 함수 내부에서는
        // 1-1. Attack() 함수의 파라미터를 변경해주세요.
        Player->Attack(Monster);



        // 3. 몬스터가 죽었는지 확인 (IsDead 호출)
        if (Monster->IsDead())
        {
            cout << "몬스터가 쓰러졌습니다! 승리!" << endl;
            break;
        }

        Sleep(500);

        // [몬스터 턴]
        // 1. 몬스터가 플레이어를 공격
        // 2. 플레이어가 데미지를 입음
        // 3. 플레이어가 죽었는지 확인
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