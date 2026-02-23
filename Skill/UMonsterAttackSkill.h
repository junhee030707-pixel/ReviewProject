#pragma once
#include "USkill.h"

class ACharacter;

class UMonsterAttackSkill : public USkill
{
public:
	UMonsterAttackSkill(ACharacter* Owner);
	virtual void Play(ACharacter* Target) = 0;
};