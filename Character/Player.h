#pragma once
#include <string>
#include "Character.h"


class APlayer : public ACharacter
{
public :
	APlayer(const string& Name, const FUnitStat& Stat);
	void LevelUp();
	void UseItem();
	
protected:
	int Level;
	int Exp;
};