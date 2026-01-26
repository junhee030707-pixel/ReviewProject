#pragma once
#include <string>
#include "Character.h"


<<<<<<< Updated upstream
class APlayer : public ACharacter
{
public :
	APlayer(const string& Name, const FUnitStat& Stat);
=======
// Monster Class <- 캐릭터 상속
// 멤버 - 별도로 추가할 건 없음.

class APlayer : public ACharacter
{
public :
	APlayer(const string& Name, const FUnitStat& Stat)
		: ACharacter(Name, Stat), Level(1), Exp(0)
	{
	}
	int Level;
	int Exp;

>>>>>>> Stashed changes
	void LevelUp();
	void UseItem();
	
protected:
	int Level;
	int Exp;
};