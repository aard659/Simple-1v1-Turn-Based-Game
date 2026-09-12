#pragma once

#include <iostream>
#include <string_view>
#include "Random.h"
#include "Weapon.h"

class Monster
{
public:
    enum Type
    {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        maxMonsterTypes,
    };

    Monster(Monster::Type type, std::string_view name, std::string_view roar, int hp, 
        Weapon::Type monsterWeapon=Weapon::fist);

    int getMonsterHealth() const;

    std::string_view getTypeString() const;

    void setMonsterWeapon(Weapon::Type weapon);

    Weapon getWeapon() const;

    void print();

    void takeDamage(int damage);

    bool isAlive() const;

private:
    Type m_type{};
    std::string m_name{ "??" };
    std::string m_roar{ "??" };
    int         m_hp{};
    Weapon m_monsterWeapon{ Weapon::fist };
};

Weapon::Type getMonsterWeapon(Monster::Type type);

namespace MonsterGenerator
{
    std::string_view getName(int n);
    std::string_view getRoar(int n);
    Monster generate();
}