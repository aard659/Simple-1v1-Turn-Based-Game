#include <iostream>
#include <string>
#include <string_view>
#include <algorithm>
#include "Player.h"
#include "Weapon.h"

int Player::getPlayerHealth() const { return m_playerHealth; }

Weapon::Type Player::getPlayerWeapon() const { return m_weapon; }

void Player::setPlayerWeapon(Weapon::Type weapon) { m_weapon = weapon; }

Player::Player(std::string_view name, Weapon::Type weapon)
	: m_name{ name }
	, m_weapon{ weapon }
{}

std::string getPlayerName()
{
	std::cout << "Enter your name warrior: ";
	std::string playerName{};
	std::getline(std::cin >> std::ws, playerName);

	return playerName;
}

// HP is clamped to 0 so it cannot become negative.
void Player::takeDamage(int damage)
{
	m_playerHealth = std::max(0, m_playerHealth - damage);
}

bool Player::isAlive() const
{
	return m_playerHealth > 0;
}