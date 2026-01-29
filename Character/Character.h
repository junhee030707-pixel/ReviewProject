// 파일명: Character.h
#pragma once
#include <iostream>
#include <string> 

using namespace std;

struct FUnitStat
{
    int MaxHp;
    int MaxMp;
    int Atk;
    int Def;
    int Critical;

    int Hp = 0;
    int Mp = 0;

    FUnitStat() 
    {}
    FUnitStat(int MaxHp, int MaxMp, int Atk, int Def, int Critical)
    {
        this->MaxHp = MaxHp;
        this->MaxMp = MaxMp;
        this->Atk = Atk;
        this->Def = Def;
        this->Critical = Critical;
    }
};

struct FDamageResult
{
    bool bCritical;
    int Damage;
};

class ACharacter
{
public:
    ACharacter(const string& NewName, const FUnitStat& NewStat);
   virtual ~ACharacter();
    
protected:
    string Name;
    FUnitStat Stat;

public:
    virtual FDamageResult Attack(ACharacter* Target);
    int TakeDamage(int DamageAmount);
    
    bool IsDead() { return Stat.Hp <= 0; }
    string GetName() const { return Name; }
    int GetHp() const { return Stat.Hp; }
};