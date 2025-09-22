#include <iostream>
#include <random>

using namespace std;

/**
 * @brief a) Write a series of if statements (use only if) that will
 * output a student’s letter grade based on the input. Assume the input (already received) is called examScore and
 * that the value of examScore is greater than 70 and less than 100.
 *
 * @return int
 */
// string getLetterGrade()
// {
//     cout << "Enter your exam score: ";
//     int examScore;
//     cin >> examScore;

//     if (examScore >= 90)
//     {
//         return "A";
//     }

//     if (examScore >= 80)
//     {
//         return "B";
//     }

//     if (examScore >= 70)
//     {
//         return "C";
//     }
// }

// string getLetterGradeWElseIf()
// {
//     cout << "Enter your exam score: ";
//     int examScore;
//     cin >> examScore;

//     if (examScore >= 90)
//     {
//         return "A";
//     }
//     else if (examScore >= 80)
//     {
//         return "B";
//     }
//     else if (examScore >= 70)
//     {
//         return "C";
//     }
//     else
//     {
//         return "D";
//     }
// }

/**
 * @brief a) Write a snippet of code that prints all odd numbers between 0 and X (inclusive),
 * where X is given by the user. Use a while loop.
 *
 * @return int
 */
void printOdds()
{
    cout << "Enter a number for while loop: ";
    int x;
    cin >> x;
    int count = 0;
    while (count <= x)
    {

        if (count % 2 == 1)
        {
            cout << "odd number: " << count << endl;
        }
        count++;
    }

    /**
     * @brief
     * int X;
    cout << "Enter a number: ";
    cin >> X;

    int i = 1;
    while (i <= X) {
        cout << i << " ";
        i += 2;
    }
     */
}

void printOddsWForLoop()
{
    cout << "Enter a number for for loop: ";
    int x;
    cin >> x;
    for (int i = 0; i <= x; i++)
    {
        if (i % 2 == 1)
        {
            cout << "odd number: " << i << endl;
        }
    }
}

void func_a(int x, int y, int z);

int main()
{

    // cout << func_a(2, 3, 4) << endl;
    // printOdds();
    // printOddsWForLoop();

    cout << 5 + 11 / 3 << endl; // 8

    signed int x = -1;   // 0xFFFFFFFF
    unsigned int y = -1; // 0xFFFFFFFF
    cout << x << endl;   // -1
    cout << y << endl;   // 4294967295

    random_device rd;                           // Hardware random source
    mt19937 gen(rd());                          // Generator initialized with seed
    uniform_int_distribution<int> dist(1, 100); // Distribution for 1-100

    // These all have operator(), so they're "callable":
    cout << rd() << endl;      // rd.operator()() - get seed
    cout << gen() << endl;     // gen.operator()() - get raw random
    cout << dist(gen) << endl; // dist.operator()(gen) - get distributed random

    return 0;

    /**
     * @brief
     *
     * Select all possible missing pieces of code so the following code snippet will print out "0.5".
        int numer = 3, denom = 6;
        cout << __________ << endl;
     *
     */

    // int numer = 4, denom = 9;
    // cout << numer / denom << endl;
    // cout << double(numer / denom) << endl;
    // cout << double(numer) / denom << endl;
    // cout << numer / double(denom) << endl;

    // int i;
    // for (i = 0; i < 8; i += 2)
    // {
    //     ++i;
    // }
    // cout << "i: " << i << endl;

    // return 0;
}