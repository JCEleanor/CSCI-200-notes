#include "InputProcessor.h"
#include <iostream>

using namespace std;

InputProcessor::InputProcessor() {}
void InputProcessor::closeStream() {}
const vector<string> &InputProcessor::getAllWords() const
{
    return allWords;
}
bool InputProcessor::openStream()
{
    return true;
}
void InputProcessor::read() {}