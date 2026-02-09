#pragma once
#include <iostream>
#include <string>
#include "Character.h"

using namespace std;

class AMonster : public ACharacter
{
public :
	AMonster(const string& Name, const FUnitStat& Stat);
	virtual FDamageResult Attack(ACharacter* Target) override;

	void UseSkill(ACharacter* Target) override;
	void Heal(int DamageAmount);
};