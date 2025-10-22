#include "OutputProcessor.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

OutputProcessor::OutputProcessor()
{
    // initialize alphabet order
    this->letterCounts.resize(26, 0);
}
void OutputProcessor::analyzeWords(const std::vector<std::string> &words, const std::string &punctuation)
{
    // step 0: clean vector;
    this->allWords.clear();
    this->uniqueWords.clear();
    this->wordCounts.clear();
    this->totalLetterCounts = 0;

    // step 1: remove punctuation
    for (const string &word : words)
    {
        string uppercaseWord = "";
        for (char character : word)
        {
            size_t foundPunctuation = punctuation.find(character);
            if (foundPunctuation == string::npos)
            {
                // step 2: to uppercase
                char upperChar = toupper(character);
                uppercaseWord += upperChar;

                if (upperChar >= 'A' && upperChar <= 'Z')
                {
                    this->letterCounts[upperChar - 'A'] += 1;
                }
            }

            // step ?: add to total letter array
        }

        // step 3: store in allWords
        this->allWords.push_back(uppercaseWord);
    }

    // step ?: set total word count
    this->totalWordCounts = this->allWords.size();
    // step 4: compute the unique set of words & store in uniqueWords
    for (const string &currentWord : this->allWords)
    {
        bool isFound = false;
        size_t index = 0;
        for (size_t i = 0; i < this->uniqueWords.size(); i++)
        {
            if (this->uniqueWords[i] == currentWord)
            {
                isFound = true;
                index = i;
                break;
            }
        }

        // step 5: count the number of occurrences of each unique word
        if (!isFound)
        {
            this->uniqueWords.push_back(currentWord);
            // new unique word, add it and set count to 1
            this->wordCounts.push_back(1);
        }
        else
        {
            // word already exists, increment its count
            this->wordCounts[index] += 1;
        }
    }
}
void OutputProcessor::closeStream() {}
bool OutputProcessor::openStream()
{
    string filename;
    cout << endl
         << "Enter filename for output file: " << endl;
    cin >> filename;

    this->fileOut.open(filename + ".txt");
    if (this->fileOut.fail())
    {
        return false;
    }

    return true;
}
void OutputProcessor::write()
{
    this->fileOut << "Read in " << this->totalWordCounts << " words";
    this->fileOut << "\n";
    this->fileOut << "Encountered " << this->uniqueWords.size() << " unique words";
    this->fileOut << "\n";

    for (size_t i = 0; i < this->uniqueWords.size(); i++)
    {
        // FIXME: fix formatting
        this->fileOut << left << setw(16) << this->uniqueWords[i] << ": " << this->wordCounts[i] << "\n";
    }

    int mostFrequentWordIndex = 0;
    for (size_t i = 1; i < this->wordCounts.size(); i++)
    {
        if (this->wordCounts[i] > this->wordCounts[mostFrequentWordIndex])
        {
            mostFrequentWordIndex = i;
        }
    }

    string mostFrequentWord = this->allWords[mostFrequentWordIndex];
    double mostFrequentWordRate = (static_cast<double>(this->wordCounts[mostFrequentWordIndex] / this->totalWordCounts)) * 100.0;
    this->fileOut << " Most Frequent Word: " << mostFrequentWord << "(" << mostFrequentWordRate << "%)" << "\n";
    this->fileOut << "Least Frequent Word: " << "aaa" << "\n";

    for (int i = 0; i < 26; i++)
    {
        // FIXME: fix formatting
        this->fileOut << (char)('A' + i) << "................." << this->letterCounts[i] << "\n";
    }
    /**
     *
        6. A list of letters and their associated counts

        7. The most frequent letter

        8. The least frequent letter
     *
     */
}