#pragma once
#include "USkill.h"

class ACharacter;

class UMonsterDrainSkill : public USkill
{
public:
	UMonsterDrainSkill(ACharacter* Owner);
	virtual void Play(ACharacter* Target) = 0;
};