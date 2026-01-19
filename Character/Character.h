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

protected:
    string Name;
    int Hp;
    int Atk;

public:
    void Attack();
    void TakeDamage(int DamageAmount);

};