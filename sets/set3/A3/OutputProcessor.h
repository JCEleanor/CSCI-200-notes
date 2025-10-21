#ifndef OUTPUTPROCESSOR_H
#define OUTPUTPROCESSOR_H

#include <fstream>
#include <vector>
#include <string>
// for header file, we will not using namespace to prevent name collision and polluted namespace

class OutputProcessor
{
private:
    std::ofstream fileOut;
    std::vector<std::string> allWords;
    std::vector<std::string> uniqueWords;
    std::vector<unsigned int> letterCounts;
    std::vector<unsigned int> wordCounts;
    unsigned int totalLetterCounts;
    unsigned int totalWordCounts;

public:
    /**
     * @brief initializes private data members to sensible values (e.g. there are no words present).
     *
     */
    OutputProcessor();
    /**
     * @brief For each word in the provided vector, remove all occurrences of all the punctuation characters denoted by the punctuation string and convert each character to its upper case equivalent. Store these modified strings in the appropriate private vector.
        The function will then compute the unique set of words present in the modified words vector. It will also count the number of occurrences of each unique word in the entire text. The private vectors will be the same size with element positions corresponding to the same word and count.
     *
     * @param words A vector of strings containing all the words.
     * @param punctuation A string denoting punctuation to remove.
     *
     */
    void analyzeWords(const std::vector<std::string> &words, const std::string &punctuation);
    /**
     * @brief Close the file stream.
     *
     */
    void closeStream();
    /**
     * @brief Prompt the user for the filename of the file they wish to write out to, then open an output file stream for the given filename.
     *
     * @return true stream opened successfully, false failed to open stream
     *
     */
    bool openStream();
    /**
     * @brief This function will print the following information to the output stream, in the order and format specified. This output must match the specification exactly.
     *
     */
    void write() const;
};

#endif