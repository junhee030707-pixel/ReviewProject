#include "Character.h"

ACharacter::ACharacter(string NewName, const FUnitStat& NewStat)
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
    if (Target == nullptr) return;

    int damage = Stat.Atk;
    bool isCritical = (rand() % 100) < Stat.Critical;

    if (isCritical)
    {

        damage = static_cast<int>(Stat.Atk * 1.5f);  // 크리티컬 배율
        cout << Name << "가 " << Target->GetName() << "을(를) 크리티컬 공격합니다! 공격력: " << damage << endl;
    }
    else
    {
        cout << Name << "가 " << Target->GetName() << "을(를) 공격합니다! 공격력: " << damage << endl;
    }

    Target->TakeDamage(damage);
}

void ACharacter::TakeDamage(int DamageAmount)
{
    if (Stat.Def >= DamageAmount)
    {
        DamageAmount = 0;
    }
    else
    {
        DamageAmount -= Stat.Def;
    }
    Stat.Hp -= DamageAmount;
    cout << Name << "가 " << DamageAmount << "의 피해를 입었습니다." << "Hp :" << Stat.Hp << endl;
}

bool ACharacter::IsDead()
{
    if (Stat.Hp <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
