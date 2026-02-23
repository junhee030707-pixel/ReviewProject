#pragma once
#include "USkill.h"

class ACharacter;

class UPlayerAttackSkill : public USkill
{
	public:
		UPlayerAttackSkill(ACharacter* Owner);
		virtual void Play(ACharacter* Target) = 0;
};