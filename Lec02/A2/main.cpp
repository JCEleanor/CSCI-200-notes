
#include <iostream>

using namespace std;

#include "samodelkin.h"

int TOTAL_ROOM;

int ROOM_EXPLORED = 0;

/**
 * @brief
 * Playing = 1, Player Won = 2, Player Lost = 3, Player Quit = 4
 */
int GAME_STATE = 1;

int ROOM_WITH_KEY = 3;
int ROOM_WITH_WEAPON = 7;
int EXIT_ROOM = 5;

int HEALTH = 100;

bool HAS_KEY = false;
bool HAS_WEAPON = false;
bool HAS_ARMOR = false;
int GOLD = 0;

int main()
{
     int difficulties;
     do
     {
          cout << "Difficulties:" << endl
               << "(1) Easy" << endl
               << "(2) Medium" << endl
               << "(3) Hard" << endl
               << "(4) Insane" << endl;

          cin >> difficulties;
     } while (difficulties != 1 && difficulties != 2 && difficulties != 3 && difficulties != 4);

     switch (difficulties)
     {
     default:
     case 1:
          TOTAL_ROOM = 10;
          break;
     case 2:
          TOTAL_ROOM = 25;
          break;
     case 3:
          TOTAL_ROOM = 50;
          break;
     case 4:
          TOTAL_ROOM = 100;
          break;
     }

     while (GAME_STATE == 1)
     {
          int currentRoom = generate_random_room_number();
          cout << endl;
          cout << "You continue deeper into the dungeon, this time exploring Room # " << currentRoom << endl;
          // Generate a random room number
          // Enter the room
          // Increment the number of rooms explored

          // 3. Enter the room
          enter_room(currentRoom, &HEALTH, &HAS_KEY, &HAS_WEAPON, &GAME_STATE, &GOLD);
          ROOM_EXPLORED++;

          if (GAME_STATE == 1)
          {
               char response;
               cout << "Do you wish to continue exploring? (Y/N): ";
               cin >> response;

               while (response != 'Y' && response != 'y' && response != 'N' && response != 'n')
               {
                    cout << "Do you wish to continue exploring? (Y/N): ";
                    cin >> response;
               }

               if (response == 'N' || response == 'n')
               {
                    GAME_STATE = 4;
               }
          }
     }
     cout << "After visiting " << ROOM_EXPLORED << " rooms, ";

     if (GAME_STATE == 2)
     {
          cout << "you have finally escaped alive!" << endl;
     }
     else if (GAME_STATE == 3)
     {
          cout << "you have fallen in battle.  Better luck next time!" << endl;
     }
     else if (GAME_STATE == 4)
     {
          cout << "you have given up, forever destined to wander the dungeon." << endl;
          if (!HAS_KEY)
          {
               cout << "Maybe you will some day find the key to unlock the gate." << endl;
          }
          if (!HAS_WEAPON)
          {
               cout << "Perhaps a sword could make the escape quicker." << endl;
          }
     }
     return 0;
}