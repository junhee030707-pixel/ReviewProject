#include <string>
#include "Player.h"

APlayer::APlayer(const string& Name, const FUnitStat& Stat)
    : ACharacter(Name, Stat), Level(1), Exp(0)
{
    cout << "[Player 생성] " << Name << " (Lv." << Level << ")" << endl;
}

void APlayer::LevelUp()
{
    
}

void APlayer::UseItem()
{
    
}

void APlayer::UseSkill(ACharacter* Target)
{
    Stat.Mp -= 10;


    int ActualDamage = Target->TakeDamage(Stat.Atk * 2);
    FDamageResult Result;
    Result.Attacker = this;
    Result.Target = Target;
    Result.bCritical = false;
    Result.Damage = ActualDamage;
    Result.PrintMessage("스킬발동: 회심의 일격...!");
}

FDamageResult APlayer::Attack(ACharacter* Target)
{
    FDamageResult result = ACharacter::Attack(Target);
    if (result.bCritical)
    {
        cout << "(이)가 대검으로(크리티컬 공격) 을(를) 무서운 오크 에게 입힙니다! " << endl;
    }

    cout << Name << "이(가) 무서운오크(을)를 공격합니다." <<  " 데미지:" << result.Damage << endl;
    cout << Target->GetName() << "HP:" << Target->GetHp() << endl;
    return result;

}
