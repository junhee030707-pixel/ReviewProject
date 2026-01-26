// 파일명: Character.h
#pragma once
#include <iostream>
#include <string> 

using namespace std;

struct FUnitStat
{
    int Hp;
    int Atk;
    int Def;
    int Critical;
};

// Player Class <- 캐릭터 상속 
// 멤버 변수: Level, Exp
// 멤버 함수: LevelUp(), UseItem()

// Monster Class <- 캐릭터 상속
// 멤버 - 별도로 추가할 건 없음.

class ACharacter
{
public:
    ACharacter(const string& NewName, const FUnitStat& NewStat);
    ~ACharacter();
    
protected:
    string Name;
    FUnitStat Stat;

public:
    void Attack(ACharacter* Target);
    void TakeDamage(int DamageAmount);
    
    bool IsDead() { return Stat.Hp <= 0; }
    string GetName() const { return Name; }
    int GetHp() const { return Stat.Hp; }
};