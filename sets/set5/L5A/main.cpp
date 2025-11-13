#include "GuessTheNumberRoom.h"
#include "ExitRoom.h"

#include <iostream>
#include <random>
using namespace std;

ARoom *go_to_next_room(int randRoomChoice)
{
    switch (randRoomChoice)
    {
    case 7:
        return new ExitRoom();
    default:
        return new GuessTheNumberRoom();
    }
}

int main()
{
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(1, 10);

    ARoom *currentRoom = nullptr;

    do
    {
        // delete the previous room to prevent memory leak
        delete currentRoom;
        currentRoom = go_to_next_room(dist(mt));
        cout << "Welcome to the " << currentRoom->getRoomName() << endl;
    } while (!currentRoom->escapeTheRoom());

    cout << "You made it out!" << endl;

    // delete final room
    delete currentRoom;
    currentRoom = nullptr;
    return 0;
}