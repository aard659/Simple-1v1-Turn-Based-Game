#include <iostream>
#include <chrono>
#include <thread>
#include "Player.h"
#include "Weapon.h"
#include "Monster.h"

void wait(int seconds) // To slow down the ouput
{
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void gameLogic(Player& player, Weapon& playerWeapon)
{
    Monster opponent{ MonsterGenerator::generate() };
    opponent.print();
    std::cout << "HP: " << opponent.getMonsterHealth() << '\n';

    wait(2);

    while ( player.isAlive() && opponent.isAlive() )
    {
        // player attack
        // Generate damage once per attack so the displayed value matches
        // the damage actually applied.
        int playerDamage{ playerWeapon.getPlayerDamage() };

        std::cout << "\nYou dealt " << playerDamage << " damage with " << playerWeapon.getName() << '\n';
        opponent.takeDamage(playerDamage);

        std::cout << "Monster HP remaining: " << opponent.getMonsterHealth() << " HP\n";

        // check if the opponent is dead
        if (!opponent.isAlive())
        {
            std::cout << "\nYou have won, Warrior! You shall receive your prize!\n";
            break;
        }

        wait(2);

        int monsterDamage{ opponent.getWeapon().getMonsterDamage() };

        std::cout << "\nMonster dealt " << monsterDamage << " damage with " << opponent.getWeapon().getName() << '\n';
        player.takeDamage(monsterDamage);

        std::cout << "Your HP remaining: " << player.getPlayerHealth() << " HP\n";

        if (!player.isAlive())
        {
            std::cout << "\nThe warrior has fallen, your brave act will always be remembered.\n";
            break;
        }
        wait(2);
    }
}

int main()
{
    std::cout << "Welcome to the arena, brave warrior! What is your name?\n";

    Player player1{ getPlayerName() };

    std::cout << "You have " << player1.getPlayerHealth() << " HP, and you will fight a monster!\n";

    Weapon::Type weapon{ chooseWeapon() };
    player1.setPlayerWeapon(weapon);
    Weapon playerWeapon{ weapon };

    std::cout << "You choose " << playerWeapon.getName() << ". Good luck, warrior!\n";
    std::cout << "Enterting the arena...\n";

    wait(2);

    gameLogic(player1, playerWeapon);
}