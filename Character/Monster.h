#pragma once
#include <iostream>
#include <string>
#include "Character.h"

using namespace std;

class AMonster : public ACharacter
{
public :
	AMonster(const string& Name, const FUnitStat& Stat) 
		: ACharacter(Name, Stat)
	{
	}
};