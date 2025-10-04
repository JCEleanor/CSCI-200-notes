#include <fstream>
#include <iostream>

using namespace std;

/**
 * @brief https://cs-courses.mines.edu/csci200/labs/lab3a.html
 *
 * @return int
 */
int main()
{
    // step 1 open fstram
    ifstream fin("./secretMessage.txt");

    // step 2 handle error
    if (fin.fail())
    {
        cout << "Failed to open file" << endl;
        return -1;
    }

    // step 3 while .get read file
    char character;
    string output;
    while (fin.get(character))
    {
        // step 4 switch case to decipher txt
        // If the character read is a newline character '\n', then you should write the newline character to the file.
        // Otherwise, if the character read is a ~, you should write a space to the file.
        // Otherwise, write the character read "offset" by +1.
        switch (character)
        {
        case '\n':
            output += character;
            break;
        case '~':
            output += " ";
            break;
        default:
            output += character + 1;
            break;
        }
    }

    // step 5 close fin
    fin.close();

    // step 6 save to decipheredMessage.txt
    ofstream outputFile("decipheredMessage.txt");
    outputFile << output;

    // step 7 close output file
    outputFile.close();

    return 0;
}