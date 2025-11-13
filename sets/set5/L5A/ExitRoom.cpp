#include "ExitRoom.h"

#include <iostream>
using namespace std;

// call the base constructor to tell the compiler to run the ARoom constructor to set up the base class members.
ExitRoom::ExitRoom() : ARoom()
{
    mRoomName = "Exit Room";
}

ExitRoom::~ExitRoom()
{
    cout << "~ExitRoom() called" << endl;
}

bool ExitRoom::escapeTheRoom()
{
    cout << "escape!" << endl;
    return true;
}