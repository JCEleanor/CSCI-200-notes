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
    int fileNum;
    cout << "Choose a file to open: " << endl;
    cout << "(1) Alice Chapter1.txt" << endl;
    cout << "(2) Green Eggs and Ham.txt" << endl;
    cout << "(3) Happy Birthday.txt" << endl;
    cout << "(4) Romeo and Juliet.txt" << endl;
    cin >> fileNum;

    string filename;
    switch (fileNum)
    {
    case 1:
        filename = "aliceChapter1.txt";
        break;
    case 2:
        filename = "greeneggsandham.txt";
        break;
    case 3:
        filename = "happybirthday.txt";
        break;
    case 4:
        filename = "romeoandjuliet.txt";
        break;
    default:
        return false;
    }

    cout << "open " << filename << endl
         << endl;

    this->fileIn.open("./input/" + filename);
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