#include "Character.h"

ACharacter::ACharacter(const string& NewName, const FUnitStat& NewStat)
{
    Name = NewName;
    Stat = NewStat;

    cout << "[생성] " << Name << "가 전장에 나타났습니다! (HP: " << Stat.Hp << ")" << endl;
}

ACharacter::~ACharacter()
{
    cout << "ACharacter 소멸됨" << endl;
}

void ACharacter::Attack(ACharacter* Target)
{
    if (Target == nullptr)
        return;
    
    int Damage = Stat.Atk;
    bool bCritical = (rand() % 100) < Stat.Critical;
    if (bCritical)
    {
        Damage = static_cast<int>(Stat.Atk * 1.5f); 
    }

    Target->TakeDamage(Damage);
}

void ACharacter::TakeDamage(int DamageAmount)
{
    DamageAmount -= Stat.Def;
    //ex) DamageAmount 가 0보다 작으면, 0반환
    //ex) DamageAmount가 0보다 크면 DamageAmount 반환.
    DamageAmount = std::max(DamageAmount, 0);
    
    Stat.Hp -= DamageAmount;
    cout << Name << "가 " << DamageAmount << "의 피해를 입었습니다." << "Hp :" << Stat.Hp << endl;
}
