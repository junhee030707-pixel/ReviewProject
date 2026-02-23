#pragma once
#include "USkill.h"

class ACharacter;

class UPlayerStrikeSkill : public USkill
{
	public:
		UPlayerStrikeSkill(ACharacter* Owner);
		virtual void Play(ACharacter* Target) override;
};