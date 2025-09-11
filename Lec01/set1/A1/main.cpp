/* CSCI 200: Assignment 1: A1 - Slot-o-mania!
 *
 * Author: Eleanor Chiu
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *
 */

#include <iostream>
#include <random>
using namespace std;

int main()
{
    // Ensure the maximum is at least 9 more than the minimum
    int minWheelRange = 9;
    int minValue, maxValue;

    // Get minimum wheel value
    cout << "What is the minimum wheel value? ";
    cin >> minValue;

    cout << "What is the maximum wheel value? ";
    cin >> maxValue;

    // Continue prompting the user until this condition is met
    while (maxValue - minValue < minWheelRange)
    {
        cout << "What is the maximum wheel value? ";
        cin >> maxValue;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(minValue, maxValue);

    int bank = 100;
    char choice;

    while (bank > 0)
    {
        int wager;

        cout << "You have $" << bank << ", how much do you wish to wager? ";
        cin >> wager;

        // Keep asking if wager is less than zero or the amount of wager is bigger than bank
        while (wager <= 0 || wager > bank)
        {
            cout << "You have $" << bank << ", how much do you wish to wager? ";
            cin >> wager;
        }

        // Generate three random numbers for the wheels
        int wheel1 = dist(gen);
        int wheel2 = dist(gen);
        int wheel3 = dist(gen);

        // Display the result
        cout << "Result: " << wheel1 << " " << wheel2 << " " << wheel3 << endl;

        if (wheel1 == wheel2 && wheel2 == wheel3)
        {
            // All three match - JACKPOT!
            cout << "JACKPOT!" << endl;

            // Win 10 times the bet
            bank += wager * 10;
        }
        else if (wheel1 == wheel2 || wheel1 == wheel3 || wheel2 == wheel3)
        {
            // Any two match - Winner
            cout << "Winner" << endl;

            // Win 3 times the bet
            bank += wager * 3;
        }
        else
        {
            // No matches - lose money
            cout << "Better luck next time" << endl;

            // Lose the wager
            bank -= wager;
        }

        // Show updated bank amount
        cout << "You now have $" << bank << endl;

        // Check if player still has money
        if (bank <= 0)
        {
            cout << "Time for you to go" << endl;
            break;
        }

        // Allow them to enter an uppercase or lowercase letter when they are choosing what to do
        do
        {
            cout << "What do you wish to do?" << endl;
            cout << "R - roll again" << endl;
            cout << "C - cash out" << endl;
            cin >> choice;
        } while (choice != 'R' && choice != 'r' && choice != 'C' && choice != 'c');

        if (choice == 'C' || choice == 'c')
        {
            cout << "Have a nice day!" << endl;
            break;
        }
    }

    return 0;
}