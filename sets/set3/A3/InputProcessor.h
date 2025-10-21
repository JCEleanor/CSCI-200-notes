#ifndef INPUTPROCESSOR_H
#define INPUTPROCESSOR_H

#include <fstream>
#include <vector>
#include <string>
// for header file, we will not using namespace to prevent name collision and polluted namespace

class InputProcessor
{
private:
    std::ifstream fileIn;
    std::vector<std::string> allWords;

public:
    /**
     * @brief Initializes any private data members to sensible values
     */
    InputProcessor();
    /**
     * @brief Close the file stream.
     */
    void closeStream();
    /**
     * @brief A vector of strings containing all the words
     *
     * @return A const reference to the vector of all words.
     */
    const std::vector<std::string> &getAllWords() const;
    /**
     * @brief Prompt the user for the filename of the file they wish to read from, then open an input file stream for the given filename.
     *
     * @return true the stream opened successfully, false otherwise
     * @return false failed to open stream
     */
    bool openStream();
    /**
     * @brief Read all the words that are in the input file and store each in the private vector of all words.
     */
    void read();
};

#endif