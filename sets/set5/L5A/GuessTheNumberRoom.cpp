#include "GuessTheNumberRoom.h"
#include "Room.h"

#include <iostream>
#include <random>
using namespace std;

GuessTheNumberRoom::GuessTheNumberRoom() // : ARoom(), _mMaxGuesses(5) // initializer list
{
    cout << "GuessTheNumberRoom() called" << endl;

    // using assignment in the body can be less efficient. The member variable is first default-constructed,
    // and then a new value is assigned to it.
    // The initializer list performs a single, direct initialization, which is often faster.
    _mMaxGuesses = 5;
    mRoomName = "Guess The Number Room";

    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(1, 20);
    _secretNumber = dist(mt);
    // std::cout << "GuessTheNumberRoom() called. Secret number is: " << _secretNumber << std::endl;
}

GuessTheNumberRoom::~GuessTheNumberRoom()
{
    cout << "~GuessTheNumberRoom() called" << endl;
}

bool GuessTheNumberRoom::escapeTheRoom()
{
    std::cout << "You have " << _mMaxGuesses << " chances to guess the secret number (between 1 and 10)." << std::endl;

    int guess;
    for (int i = 0; i < _mMaxGuesses; i++)
    {
        std::cout << "Guess #" << (i + 1) << ": ";
        std::cin >> guess;

        if (guess == _secretNumber)
        {
            std::cout << "Congratulations! You guessed the secret number and escaped!" << std::endl;
            return true;
        }
        else if (guess < _secretNumber)
        {
            std::cout << "Too low! Try again." << std::endl;
        }
        else
        {
            std::cout << "Too high! Try again." << std::endl;
        }
    }

    std::cout << "You ran out of guesses! You are still trapped in the " << mRoomName << "." << std::endl;
    return false;
}