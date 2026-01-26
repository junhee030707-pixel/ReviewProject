#include "Character.h"

ACharacter::ACharacter(string NewName, int NewHp, int NewAtk, int NewDef, float NewCritical)
{
    Name = NewName;
    Hp = NewHp;
    Atk = NewAtk;
    Def = NewDef;
    Critical = NewCritical;

    cout << "[생성] " << Name << "가 전장에 나타났습니다! (HP: " << Hp << ")" << endl;
}
ACharacter::~ACharacter()
{
    cout << "ACharacter 소멸됨" << endl;
}

void ACharacter::Attack(ACharacter* Target)
{
    if (Target == nullptr) return;

    int damage = Atk;
    bool isCritical = (rand() % 100) < Critical;

    if (isCritical)
    {

        damage = static_cast<int>(Atk * 1.5f);  // 크리티컬 배율
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
    if (Def >= DamageAmount)
    {
        DamageAmount = 0;
    }
    else
    {
        DamageAmount -= Def;
    }
    Hp -= DamageAmount;
    cout << Name << "가 " << DamageAmount << "의 피해를 입었습니다." << "Hp :" << Hp << endl;
}

bool ACharacter::IsDead()
{
    if (Hp <=0) 
    {
        return true;
    } 
    else
    {
        return false;
    }
}
