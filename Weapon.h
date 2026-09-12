#pragma once

class Weapon
{
public:
	enum Type
	{
		fist,
		sword,
		bow,
		dagger,
		staff,
		fireBall,
		maxWeaponType,
	};

	Weapon(Type type);

	std::string_view getName() const;

	int getPlayerDamage() const;
	int getMonsterDamage() const;

private:
	Type m_type{};
};

Weapon::Type chooseWeapon();