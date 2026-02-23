#include "Character.h"

ACharacter::ACharacter(const string& NewName, const FUnitStat& NewStat)
{
    Name = NewName;
    Stat = NewStat;

    Stat.Hp = Stat.MaxHp;
    Stat.Mp = Stat.MaxMp;

    cout << "[생성] " << Name << "가 전장에 나타났습니다! (HP: " << Stat.Hp << ")" << endl;
}

ACharacter::~ACharacter()
{
    cout << "ACharacter 소멸됨" << endl;
}

FDamageResult ACharacter::Attack(ACharacter* Target)
{
    if (Target == nullptr)
        return FDamageResult();
    
    
    int Damage = Stat.Atk;
    bool bCritical = (rand() % 100) < Stat.Critical;
    if (bCritical)
    {
        Damage = static_cast<int>(Stat.Atk * 1.5f); 
    }

    int FinalDamage = Target->TakeDamage(Damage);
    FDamageResult result;
    result.Damage = FinalDamage;
    result.bCritical = bCritical;
    return result;
}

int ACharacter::TakeDamage(int DamageAmount)
{
    DamageAmount -= Stat.Def;
    //ex) DamageAmount 가 0보다 작으면, 0반환
    //ex) DamageAmount가 0보다 크면 DamageAmount 반환.
    DamageAmount = std::max(DamageAmount, 0);
    
    Stat.Hp -= DamageAmount;
    
    return DamageAmount;
}

void ACharacter::PrintName()
{
    cout << "[" << Name << "] ";
}
void FDamageResult::PrintMessage(const string& AttackMessage)
{
    cout << "-------------------------------------------------" << endl;
    Attacker->PrintName();
    cout << AttackMessage << '\n';

    Target->PrintName();
    cout << "'받은 데미지': " << Damage << "-> '남은 HP': " << Target->GetHp() << endl;
    cout << "-------------------------------------------------" << endl;
}

void ACharacter::ShowStat()
{
    PrintName();
    cout << "HP: " << Stat.Hp <<  " / " << Stat.MaxHp << " " "|" << " " "MP: " << Stat.Mp << "/" << Stat.MaxMp << endl;
}
void ACharacter::DoAction(ACharacter* Target)
{
    if (rand() % 100 <= 50) 
    {
		Attack(Target);
    }
    else 
    {
        UseSkill(Target);
	}
}

void ACharacter::Heal(int DamageAmount)
{
    int PrevHp = Stat.Hp;
    Stat.Hp += DamageAmount;
    Stat.Hp = min(Stat.Hp, Stat.MaxHp);
    int ActualHeal = Stat.Hp - PrevHp; //힐 한 후 Hp - 힐 전 Hp  
    PrintName();
    cout << ActualHeal << "Hp를 회복했다" << endl;
}
