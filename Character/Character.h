// 파일명: Character.h
#pragma once
#include <iostream>
#include <string> // 문자열(이름)을 쓰기 위해 필요합니다.

using namespace std;

class ACharacter
{
public:
    ACharacter();
    ~ACharacter();

    // [과제 1] 값을 받는 생성자 선언하기
   // 이름, 체력, 공격력을 입력받아서 생성합니다.
    ACharacter(string NewName, int NewHp, int NewAtk);

protected:
    string Name;
    int Hp;
    int Atk;

public:
    void Attack(ACharacter* Target);
    void TakeDamage(int DamageAmount);
    int GetHp();
    string GetName();
    bool IsDead();

};