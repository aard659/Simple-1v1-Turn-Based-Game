#include <iostream>
#include <string_view>
#include "Weapon.h"
#include "Random.h"

Weapon::Weapon(Type type)
	: m_type{ type }
{}

void ignoreLine()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool hasUnextractedInput()
{
	return !std::cin.eof() && std::cin.peek() != '\n';
}

Weapon::Type chooseWeapon()
{
	std::cout << "choose your weapon! \n";
	std::cout << "0 = Fist   (1-3 damage)\n" <<
		"1 = Sword  (11-15 damage)\n" <<
		"2 = Bow    (9-12 damage)\n" <<
		"3 = Dagger (7-10 damage)\n" <<
		"4 = Staff  (14-17 damage)\n";

	int weapon{};
	
	while (true)
	{
		std::cin >> weapon;

		if (!std::cin || hasUnextractedInput())
		{
			std::cin.clear();
			ignoreLine();
			continue;
		}

		if (weapon < 0 || weapon > 4)
		{
			ignoreLine();
			continue;
		}

		ignoreLine();
		return static_cast<Weapon::Type>(weapon);
	}
}

std::string_view Weapon::getName() const
{
	switch (m_type)
	{
	case Weapon::fist:		return "Fist";
	case Weapon::sword:		return "Sword";
	case Weapon::bow:		return "Bow";
	case Weapon::dagger:	return "Dagger";
	case Weapon::staff:		return "Staff";
	case Weapon::fireBall:	return "Fire Ball";

	default:		return	"??";
	}
}

int Weapon::getPlayerDamage() const
{
	switch (m_type)
	{
	case Weapon::fist:		return Random::get(1, 3);
	case Weapon::sword:		return Random::get(8, 12);
	case Weapon::bow:		return Random::get(7, 10);
	case Weapon::dagger:	return Random::get(6, 9);
	case Weapon::staff:		return Random::get(10, 13);

	default: return 0;
	}
}

// Monster damage is slightly higher because the player always attacks first.
int Weapon::getMonsterDamage() const
{
	switch (m_type)
	{
	case Weapon::fist:		return Random::get(1, 3);
	case Weapon::sword:		return Random::get(10, 14);
	case Weapon::bow:		return Random::get(8, 12);
	case Weapon::dagger:	return Random::get(7, 11);
	case Weapon::fireBall:	return Random::get(14, 18);

	default: return 0;
	}
}