// 파일명: Character.h
#pragma once
#include <iostream>
#include <string> 

using namespace std;

class ACharacter
{
public:
    ACharacter(string NewName, int NewHp, int NewAtk, int NewDef, float NewCritical);
    ~ACharacter();
protected:
    string Name;
    int Hp;
    int Atk;
    int Def;
    float Critical;

public:
    void Attack(ACharacter* Target);
    void TakeDamage(int DamageAmount);
    bool IsDead();

    string GetName() const { return Name; };
    int GetHp() const { return Hp; };

};