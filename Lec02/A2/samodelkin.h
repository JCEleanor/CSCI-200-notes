#ifndef SAMODELKIN_H
#define SAMODELKIN_H

#include <iostream>

using namespace std;

/**
 * @brief Task: Generates a random integer within the range 1 and the number of rooms that exist
 *
 * Easy - 10 rooms
Medium - 25 rooms
Hard - 50 rooms
Insane - 100 rooms
 */
int generate_random_room_number();

/**
 * @brief Task: Prints a message saying there is nothing in here.
 *
 */
void empty_room();

/**
 * @brief Prints a message alluding there is something in this room.
If the user already has the key, prints a message saying the key was already found.
If the user doesn't have the key, ask the user if they wany to pick something up.
If the user says they wish to pick something up, then set the boolean to be true and print a message saying the key has been found.
If the user does not want to pick something up, then print a message warning this may be a bad choice.
 *
 * @param hasKey
 */
void key_room(bool *hasKey);

/**
 * @brief Prints a message alluding there is something in this room.
If the user already has a weapon, prints a message saying the weapon was already found.
If the user doesn't have a weapon, ask the user if they wany to pick something up.
If the user says they wish to pick something up, then set the boolean to be true and print a message saying the weapon has been found.
If the user does not want to pick something up, then print a message warning this may be a bad choice
 *
 * @param hasWeapon
 */
void weapon_room(bool *hasWeapon);

/**
 * @brief  Generate a random integer in the inclusive range of 20 to 35 for the enemy's health and print this value.
Simulate a battle until the enemy health is no longer positive or the hero's health is no longer positive.
Each round of the battle both the enemy and hero attack simultaneously.
The enemy attack is a random integer in the inclusive range of 5 to 10. Print the enemy damage done and deduct from the hero's health.
If the hero has a weapon, then the damage is a random integer in the inclusive range of 10 to 15.
If the hero does not have a weapon, the damage is a random integer in the inclusive range of 1 to 5.
Print the hero damage done and deduct from the enemy's health.
If the enemy dies, then print a message stating it is slain.
If the hero dies, then set the game state to the lose state and print a message the hero died.
 *
 * @param hasWeapon
 * @param currentHealth
 * @param gameState
 */
void enemy_room(bool hasWeapon, int *heroHealth, int *gameState);

/**
 * @brief Generates a random integer between the inclusive range of 5 and 15.
 * Adds this to the hero's health and prints how much health was added.
 *
 * @param currentHealth An integer for the hero's current health
 */
void potion_room(int *currentHealth);

/**
 * @brief
 * Prints a message there is a locked gate.
If the hero has the key, set the game state to the win state and print a message that the gate is unlocked.
Otherwise, print a message to continue searching.

 * @param hasKey
 * @param gameState
 */
void exit_room(bool hasKey, int *gameState);

/**
 * @brief Cleanly prints what room number the hero is in,
 * the hero's current health, and what is currently in the hero's inventory (key and/or weapon).
If the current room number is the key room number, then calls key_room.
If the current room number is the weapon room number, then calls weapon_room.
If the current room number is the exit room number, then calls exit_room.
Otherwise, there is a 1 in 5 chance the room is empty. There is a 1 in 5 chance the room contains a potion.
There is a 3 in 5 chance the room contains an enemy. Note: this isn't a random chance.
The same room number will always map to the same outcome every time the hero visits that room number.
(Hint: modulus is handy here.)
 *
 * @param roomNo
 * @param currentHealth
 * @param hasKey
 * @param hasWeapon
 * @param gameState
 */
void enter_room(int roomNo, int *currentHealth, bool *hasKey, bool *hasWeapon, int *gameState, int *GOLD);

#endif