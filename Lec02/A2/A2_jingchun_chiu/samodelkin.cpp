#include "samodelkin.h"
#include <random>

// will be set in main.cpp
extern int TOTAL_ROOM;
extern int ROOM_WITH_KEY;
extern int ROOM_WITH_WEAPON;
extern int ROOM_WITH_ARMOR;
extern int EXIT_ROOM;

string printHelper(bool booleanValue)
{
    if (booleanValue == true)
    {
        return "Yes";
    }
    else
    {
        return "No";
    }
}

int generate_random_room_number()
{

    cout << "generate_random_room_number " << TOTAL_ROOM << endl;
    random_device rd;
    mt19937 gen(rd());
    // TODO: get value from global int
    uniform_int_distribution<int> dist(1, TOTAL_ROOM);

    return dist(gen);
}

void key_room(bool *hasKey)
{
    cout << "There is something in this room" << endl;
    if (*hasKey)
    {
        cout << "You already have the key" << endl;
    }
    else
    {
        char isPickKey;
        cout << "Do you want to pick up the key? (Y?N) " << endl;
        cin >> isPickKey;

        while (isPickKey != 'Y' && isPickKey != 'y' && isPickKey != 'N' && isPickKey != 'n')
        {
            cout << "You notice something shiny in the corner.  Do you wish to pick it up? (Y/N): ";
            cin >> isPickKey;
        }

        if (isPickKey == 'Y' || isPickKey == 'y')
        {
            // TODO: set the memory address to true
            *hasKey = true;
            cout << "The key has been found" << endl;
        }
        else
        {
            cout << "You might regret this lol" << endl;
        }
    }
}

void weapon_room(bool *hasWeapon)
{
    cout << "You appear to be in what was once an armory of sorts. There are many broken weapons and shields scattered about." << endl;

    if (*hasWeapon)
    {
        cout << "You already took the weapon from here." << endl;
    }
    else
    {
        char response;
        cout << "Mounted upon the wall is the mighty sword Excalibur.  Do you wish to take it with you? (Y/N): ";
        cin >> response;

        while (response != 'Y' && response != 'y' && response != 'N' && response != 'n')
        {
            cout << "Mounted upon the wall is the mighty sword Excalibur.  Do you wish to take it with you? (Y/N): ";
            cin >> response;
        }

        if (response == 'Y' || response == 'y')
        {
            *hasWeapon = true;
            cout << "You instantly feel more powerful." << endl;
        }
        else
        {
            cout << "You hope you don't regret that choice." << endl;
        }
    }
}

void armor_room(bool *hasArmor)
{
    cout << "You appear to be in what was once an armory of sorts. There are many broken armor scattered about." << endl;

    if (*hasArmor)
    {
        cout << "You already took the armor from here." << endl;
    }
    else
    {
        char response;
        cout << "Mounted upon the wall is the mighty armor XYZ.  Do you wish to take it with you? (Y/N): ";
        cin >> response;

        while (response != 'Y' && response != 'y' && response != 'N' && response != 'n')
        {
            cout << "Mounted upon the wall is the mighty armor XYZ.  Do you wish to take it with you? (Y/N): ";
            cin >> response;
        }

        if (response == 'Y' || response == 'y')
        {
            *hasArmor = true;
            cout << "You instantly feel more protected." << endl;
        }
        else
        {
            cout << "You hope you don't regret that choice." << endl;
        }
    }
}

void enemy_room(bool hasWeapon, bool hasArmor, int *heroHealth, int *gameState, int *GOLD)
{
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> enemyHealthDist(20, 35);
    uniform_int_distribution<int> enemyDamageDist(5, 10);
    uniform_int_distribution<int> heroWeaponDist(10, 15);
    uniform_int_distribution<int> heroNoWeaponDist(1, 5);

    int enemyHealth = enemyHealthDist(gen);
    cout << "There's a monster with " << enemyHealth << "HP in here!  Battle ensues!" << endl;

    while (enemyHealth > 0 && *heroHealth > 0)
    {
        int heroDamage;
        if (hasWeapon)
        {
            heroDamage = heroWeaponDist(gen);

            if (hasArmor)
            {
                cout << "The shiny armor protected you from the attack. Damage drops from " << heroDamage << " to " << heroDamage / 2 << endl;
                heroDamage = heroDamage / 2;
            }

            cout << "You swing Excalibur dealing " << heroDamage << " damage." << endl;
        }
        else
        {
            heroDamage = heroNoWeaponDist(gen);
            cout << "You punch the beast dealing " << heroDamage << " damage." << endl;
        }
        enemyHealth -= heroDamage;

        int enemyDamage = enemyDamageDist(gen);
        cout << "The beast beats you dealing " << enemyDamage << " damage." << endl;
        *heroHealth -= enemyDamage;
    }

    if (enemyHealth <= 0)
    {
        cout << "You have slain the enemy." << endl;
        uniform_int_distribution<int> discoverGold(1, 100);

        *GOLD = discoverGold(gen);
        cout << "You discover " << *GOLD << " pounds of gold!" << endl;
    }

    if (*heroHealth <= 0)
    {
        *gameState = 3;
        cout << "You have been defeated by the monster!" << endl;
    }
}

void potion_room(int *heroHealth)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(5, 15);

    int healthRestored = dist(gen);
    *heroHealth += healthRestored;
    cout << "A fountain flows in the middle of the room.  Cautiously you take a drink." << endl;
    cout << "You've restored " << healthRestored << "HP." << endl;
}

void exit_room(bool hasKey, int *gameState)
{
    cout << "There's a massive locked gate blocking your way." << endl;

    if (hasKey)
    {
        *gameState = 2;
        cout << "You try the key you found earlier.  It fits!" << endl;
    }
    else
    {
        cout << "Perhaps you need to find a key somewhere?" << endl;
    }
}

void empty_room()
{
    cout << "You look around, there's nothing here" << endl;
}

void enter_room(int currentRoom, int *HEALTH, bool *HAS_KEY, bool *HAS_WEAPON, int *GAME_STATE, int *GOLD, bool *HAS_ARMOR)
{
    printf("You enter room #%d.  You have %dHP, Key = %s, Weapon = %s, Armor = %s, Gold = %dGP\n", currentRoom, *HEALTH, printHelper(*HAS_KEY).c_str(), printHelper(*HAS_WEAPON).c_str(), printHelper(*HAS_ARMOR).c_str(), *GOLD);

    if (currentRoom == ROOM_WITH_KEY)
    {
        key_room(HAS_KEY);
    }
    else if (currentRoom == ROOM_WITH_ARMOR)
    {
        armor_room(HAS_ARMOR);
    }
    else if (currentRoom == ROOM_WITH_WEAPON)
    {
        weapon_room(HAS_WEAPON);
    }
    else if (currentRoom == EXIT_ROOM)
    {
        exit_room(*HAS_KEY, GAME_STATE);
    }
    else
    {
        int outcome = currentRoom % 5;

        if (outcome == 0)
        {
            empty_room();
        }
        else if (outcome == 1)
        {
            potion_room(HEALTH);
        }
        else
        {
            enemy_room(*HAS_WEAPON, *HAS_ARMOR, HEALTH, GAME_STATE, GOLD);
        }
    }
}
