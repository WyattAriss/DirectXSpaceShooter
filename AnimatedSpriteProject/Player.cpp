#include "pch.h"
#include "Player.h"


Player::Player()
	: m_attackSpeed(1.0f)
{
	mPlayerShipTexture = std::make_shared<AnimatedTexture>();
	mPlayerWeaponTexture = std::make_shared<AnimatedTexture>();
}


Player::~Player()
{
}

float Player::GetAttackSpeed() const
{
	return this->m_attackSpeed;
}

std::shared_ptr<AnimatedTexture> Player::GetShipTexture() const
{
	return this->mPlayerShipTexture;
}

std::shared_ptr<AnimatedTexture> Player::GetWeaponTexture() const
{
	return this->mPlayerWeaponTexture;
}

