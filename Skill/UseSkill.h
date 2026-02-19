#pragma once

class ACharacter;

class UseSkill
{
public:
	UseSkill(ACharacter* Owner) : Owner(Owner) 
	{
	}
	virtual ~UseSkill(){}
	virtual void Play(ACharacter* Target) = 0;
	

protected:
	ACharacter* Owner;
};