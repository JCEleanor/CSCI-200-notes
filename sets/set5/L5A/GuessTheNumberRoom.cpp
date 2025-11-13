#include "GuessTheNumberRoom.h"

#include <iostream>
#include <random>
using namespace std;

GuessTheNumberRoom::GuessTheNumberRoom() {
    cout << "GuessTheNumberRoom() called" << endl;

    random_device rd;
    mt19937 mt( rd() );
    uniform_int_distribution<int> dist(1, 20);
    _secretNumber = dist( mt );
}

GuessTheNumberRoom::~GuessTheNumberRoom() {
    cout << "~GuessTheNumberRoom() called" << endl;
}