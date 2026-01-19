#include <iostream>
#include "Character/Character.h"

int main()
{
    // 1 캐릭터 생성
    ACharacter* Char = new ACharacter();
    Char->Attack();
    Char->TakeDamage(30);
    delete Char;

    return 0;


}