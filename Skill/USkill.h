#pragma once

class ACharacter;

class USkill
{
public:
	USkill(ACharacter* Owner) : Owner(Owner) 
	{
	}
	virtual ~USkill(){}
	virtual void Play(ACharacter* Target) = 0;
	

protected:
	ACharacter* Owner;
};