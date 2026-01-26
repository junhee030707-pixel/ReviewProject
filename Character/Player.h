#pragma once
#include <string>
#include "Character.h"

// Player Class <- 캐릭터 상속 
// 멤버 변수: Level, Exp
// 멤버 함수: LevelUp(), UseItem()

// Monster Class <- 캐릭터 상속
// 멤버 - 별도로 추가할 건 없음.

class Player : public ACharacter
{
public :
	Player(const string& Name, const FUnitStat& Stat)
		: ACharacter(Name, Stat), Level(1), Exp(0)
	{
	}
	int Level;
	int Exp;

	void LevelUp();
	void UseItem();
};