#pragma once
#include <string>
#include "Character.h"


class APlayer : public ACharacter
{
public :
	APlayer(const string& Name, const FUnitStat& Stat);
	virtual FDamageResult Attack(ACharacter* Target) override;
	void LevelUp();
	void UseItem();
	void UseSkill(ACharacter* Target) override;
	
protected:
	int Level;
	int Exp;
};