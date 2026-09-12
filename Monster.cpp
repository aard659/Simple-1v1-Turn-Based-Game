#include <string_view>
#include "Monster.h"
#include "Weapon.h"

Monster::Monster(Monster::Type type, std::string_view name, std::string_view roar, int hp, 
    Weapon::Type monsterWeapon)
    : m_type{ type }
    , m_name{ name }
    , m_roar{ roar }
    , m_hp{ hp }
    , m_monsterWeapon{ monsterWeapon }
{}

int Monster::getMonsterHealth() const { return m_hp; }

std::string_view Monster::getTypeString() const
{
    switch (m_type)
    {
    case dragon:   return "dragon";
    case goblin:   return "goblin";
    case ogre:     return "ogre";
    case orc:      return "orc";
    case skeleton: return "skeleton";
    case troll:    return "troll";
    case vampire:  return "vampire";
    case zombie:   return "zombie";

    default: return "??";
    }
}

void Monster::setMonsterWeapon(Weapon::Type weapon) { m_monsterWeapon = weapon; }

Weapon Monster::getWeapon() const { return m_monsterWeapon; }

Weapon::Type getMonsterWeapon(Monster::Type type)
{
    switch (type)
    {
    case Monster::goblin:
    case Monster::orc:
    case Monster::ogre:
    case Monster::troll:
        return Weapon::sword;

    case Monster::skeleton:
        return Weapon::bow;

    case Monster::zombie:
    case Monster::vampire:
        return Weapon::dagger;

    case Monster::dragon:
        return Weapon::fireBall;

    default:
        return Weapon::fist;
    }
}

namespace MonsterGenerator
{
    std::string_view getName(int n)
    {
        switch (n)
        {
        case 0: return "Borg";
        case 1: return "Kirk";
        case 2: return "Shaq";
        case 3: return "Wowo";
        case 4: return "Mol";
        case 5: return "Krill";

        default: return "??";
        }
    }

    std::string_view getRoar(int n)
    {
        switch (n)
        {
        case 0: return "ROAR";
        case 1: return "squeal";
        case 2: return "howl";
        case 3: return "GROWL";
        case 4: return "swis";
        case 5: return "SCREECH";

        default: return "??";
        }
    }

    Monster generate()
    {
        Monster::Type type{ static_cast<Monster::Type>(Random::get(0, Monster::maxMonsterTypes - 1)) };

        return Monster{
            type,
            getName(Random::get(0, 5)),
            getRoar(Random::get(0, 5)),
            Random::get(60, 130),
            getMonsterWeapon(type) };
    }
}

void Monster::print()
{
    std::cout << '\n' << m_name << " the " << getTypeString() << " has appeared!\n";
}

// HP is clamped to 0 so it cannot become negative.
void Monster::takeDamage(int damage)
{
    m_hp = std::max(0, m_hp - damage);
}

bool Monster::isAlive() const
{
    return m_hp > 0;
}