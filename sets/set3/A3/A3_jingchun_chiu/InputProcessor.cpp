#include "InputProcessor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

InputProcessor::InputProcessor() {}
void InputProcessor::closeStream() {}
const vector<string> &InputProcessor::getAllWords() const
{
    return allWords;
}
bool InputProcessor::openStream()
{
    std::string userInput;
    cout << "Choose a file to open or enter filename: " << endl;
    cout << "(1) Alice Chapter1.txt" << endl;
    cout << "(2) Green Eggs and Ham.txt" << endl;
    cout << "(3) Happy Birthday.txt" << endl;
    cout << "(4) Romeo and Juliet.txt" << endl;
    cin >> userInput;

    string filename;
    if (userInput.length() == 1)
    {

        switch (userInput[0])
        {
        case '1':
            filename = "aliceChapter1.txt";
            break;
        case '2':
            filename = "greeneggsandham.txt";
            break;
        case '3':
            filename = "happybirthday.txt";
            break;
        case '4':
            filename = "romeoandjuliet.txt";
            break;
        }

        filename = "./input/" + filename;
    }
    else
    {
        // assume user include dir & file extension
        filename = userInput;
    }

    this->fileIn.open(filename);
    if (this->fileIn.fail())
    {
        cerr << "Error opening file " << filename << endl;
        return false;
    }

    return true;
}
void InputProcessor::read()
{
    std::string word;
    while (fileIn >> word)
    {
        allWords.push_back(word);
    }
}