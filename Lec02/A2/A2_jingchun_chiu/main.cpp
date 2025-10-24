
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
int ROOM_WITH_ARMOR = 8;
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

     // Track visited rooms and first populate all the values to false
     // The new operator expects an unsigned size, so casting it to unsigned long
     bool *visitedRooms = new bool[static_cast<unsigned long>(TOTAL_ROOM + 1)];
     for (int i = 0; i <= TOTAL_ROOM; i++)
     {
          visitedRooms[i] = false;
     }

     while (GAME_STATE == 1)
     {
          bool validRoom = false;
          int currentRoom;

          while (!validRoom)
          {
               currentRoom = generate_random_room_number();

               if (currentRoom == EXIT_ROOM)
               {
                    // Exit room can always be visited
                    validRoom = true;
               }
               else if (currentRoom == ROOM_WITH_KEY && !HAS_KEY)
               {
                    // Key room can be visited if key not yet obtained
                    validRoom = true;
               }
               else if (currentRoom == ROOM_WITH_WEAPON && !HAS_WEAPON)
               {
                    // Weapon room can be visited if weapon not yet obtained
                    validRoom = true;
               }
               else if (currentRoom == ROOM_WITH_ARMOR && !HAS_ARMOR)
               {
                    // Armor room can be visited if weapon not yet obtained
                    validRoom = true;
               }
               else if (!visitedRooms[currentRoom])
               {
                    // Any unvisited room is valid
                    validRoom = true;
               }
          }

          cout << endl;
          cout << "You continue deeper into the dungeon, this time exploring Room # " << currentRoom << endl;

          // Mark room as visited (except exit room)
          if (currentRoom != EXIT_ROOM)
          {
               visitedRooms[currentRoom] = true;
          }

          enter_room(currentRoom, &HEALTH, &HAS_KEY, &HAS_WEAPON, &GAME_STATE, &GOLD, &HAS_ARMOR);
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