#pragma once
#include "AnimatedTexture.h"

class Player
{
public:
	Player();
	~Player();

	float GetAttackSpeed() const;

	std::shared_ptr<AnimatedTexture> GetShipTexture() const;

	std::shared_ptr<AnimatedTexture> GetWeaponTexture() const;

private:
	float m_attackSpeed;

	std::shared_ptr<AnimatedTexture> mPlayerShipTexture;
	std::shared_ptr<AnimatedTexture> mPlayerWeaponTexture;
};

