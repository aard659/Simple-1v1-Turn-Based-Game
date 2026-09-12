#pragma once

#include <string>
#include <string_view>
#include "Weapon.h"

class Player
{
public:
	int getPlayerHealth() const;

	Weapon::Type getPlayerWeapon() const;

	void setPlayerWeapon(Weapon::Type weapon);

	Player(std::string_view name, Weapon::Type weapon=Weapon::fist);

	void takeDamage(int damage);

	bool isAlive() const;

private:
	std::string m_name{ "Player" };
	int m_playerHealth{ 100 };
	Weapon::Type m_weapon{ Weapon::fist };
};

std::string getPlayerName();