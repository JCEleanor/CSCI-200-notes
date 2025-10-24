#include "OutputProcessor.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

size_t OutputProcessor::_getMaxIndex(const std::vector<unsigned int> &targetArray)
{
    size_t maxIndex = 0;
    for (size_t i = 1; i < targetArray.size(); i++)
    {
        if (targetArray[i] > targetArray[maxIndex])
        {
            maxIndex = i;
        }
    }

    return maxIndex;
}

size_t OutputProcessor::_getMinIndex(const std::vector<unsigned int> &targetArray)
{
    size_t minIndex = 0;
    for (size_t i = 1; i < targetArray.size(); i++)
    {
        if (targetArray[i] < targetArray[minIndex])
        {
            minIndex = i;
        }
    }

    return minIndex;
}

size_t OutputProcessor::_getLongestWordLength(const std::vector<std::string> &targetArray)
{
    if (targetArray.empty())
    {
        return 0;
    }
    std::string longestWord = targetArray[0];
    for (size_t i = 1; i < targetArray.size(); i++)
    {
        if (targetArray[i].length() > longestWord.length())
        {
            longestWord = targetArray[i];
        }
    }

    return longestWord.length();
}

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
                    this->totalLetterCounts += 1;
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
         << "Enter filename for output file: ";
    cin >> filename;

    this->fileOut.open(filename + ".out");
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

    int longestWordLegth = this->_getLongestWordLength(this->uniqueWords);
    size_t mostFrequentWordIndex = this->_getMaxIndex(this->wordCounts);

    // calculate column width
    int maxCount = this->wordCounts[mostFrequentWordIndex];
    int countWidth = to_string(maxCount).length();

    // sort alphabetically
    vector<string> sortedWords = this->uniqueWords;
    vector<unsigned int> sortedCounts = this->wordCounts;

    for (size_t i = 0; i < sortedWords.size(); i++)
    {
        size_t minIndex = i;
        for (size_t j = i; j < sortedWords.size(); j++)
        {
            if (sortedWords[j] < sortedWords[minIndex])
            {
                minIndex = j;
            }
        }

        // swap the words in the copied vector
        string tempWord = sortedWords[i];
        sortedWords[i] = sortedWords[minIndex];
        sortedWords[minIndex] = tempWord;

        // swap the counts in the copied vector to keep them in sync
        unsigned int tempCount = sortedCounts[i];
        sortedCounts[i] = sortedCounts[minIndex];
        sortedCounts[minIndex] = tempCount;
    }

    for (size_t i = 0; i < sortedWords.size(); i++)
    {
        this->fileOut << left << setw(longestWordLegth) << sortedWords[i] << " : ";
        this->fileOut << right << setw(countWidth) << sortedCounts[i] << "\n";
    }

    size_t leastFrequentWordIndex = this->_getMinIndex(this->wordCounts);
    string mostFrequentWord = this->uniqueWords[mostFrequentWordIndex];
    string leastFrequentWord = this->uniqueWords[leastFrequentWordIndex];

    double mostFrequentWordCount = (static_cast<double>(this->wordCounts[mostFrequentWordIndex]));
    double leastFrequentWordCount = (static_cast<double>(this->wordCounts[leastFrequentWordIndex]));
    double mostFrequentWordRate = (mostFrequentWordCount / this->totalWordCounts) * 100.0;
    double leastFrequentWordRate = (leastFrequentWordCount / this->totalWordCounts) * 100.0;

    // calculate column width
    int wordWidth = (mostFrequentWord.length() > leastFrequentWord.length()) ? mostFrequentWord.length() : leastFrequentWord.length();
    int numberWidth = to_string(this->wordCounts[mostFrequentWordIndex]).length();

    // WORD# - The word. Left align all values. Allocate enough space for the length of the longer of the two words.
    // #C - The corresponding count of the word. Right align all values. Allocate enough space for the length of the most frequent word present in the file.
    // #P - The frequency of the word. Right align all values. Print to three decimal places.
    this->fileOut << " Most Frequent Word: ";
    this->fileOut << left << setw(wordWidth) << mostFrequentWord << " ";
    this->fileOut << right << setw(numberWidth) << this->wordCounts[mostFrequentWordIndex];
    this->fileOut << " (" << fixed << setprecision(3) << mostFrequentWordRate << "%)" << "\n";

    this->fileOut << "Least Frequent Word: ";
    this->fileOut << left << setw(wordWidth) << leastFrequentWord << " ";
    this->fileOut << right << setw(numberWidth) << this->wordCounts[leastFrequentWordIndex];
    this->fileOut << " (" << fixed << setprecision(3) << leastFrequentWordRate << "%)" << "\n";

    // The width needs to match the width of the word table from above.
    // the sum of the longest word's length, the separator (" : "), and the width of the count column
    int tableWidth = longestWordLegth + 3 + countWidth;
    int letterCountWidth = tableWidth - 1;
    this->fileOut << std::setfill('.');
    for (int i = 0; i < 26; i++)
    {
        this->fileOut << left << (char)('A' + i);
        this->fileOut << right << setw(letterCountWidth) << this->letterCounts[i] << "\n";
    }

    this->fileOut << setfill(' ');

    // FIXME: if same count, sort by alphebetical orderx
    size_t mostFrequentLetterIndex = this->_getMaxIndex(this->letterCounts);
    size_t leastFrequentLetterIndex = this->_getMinIndex(this->letterCounts);

    char mostFrequentLetter = (char)('A' + mostFrequentLetterIndex);
    char leastFrequentLetter = (char)('A' + leastFrequentLetterIndex);

    double mostFrequentLetterCount = (static_cast<double>(this->letterCounts[mostFrequentLetterIndex]));
    double leastFrequentLetterCount = (static_cast<double>(this->letterCounts[leastFrequentLetterIndex]));

    double maxFrequentLetterRate = (mostFrequentLetterCount / this->totalLetterCounts) * 100.0;
    double leastFrequentLetterRate = (leastFrequentLetterCount / this->totalLetterCounts) * 100.0;

    this->fileOut << setw(23) << "Most Frequent Letter: " << mostFrequentLetter << " ";
    this->fileOut << right << setw(3) << this->letterCounts[mostFrequentLetterIndex] << " ";
    this->fileOut << "(" << setw(7) << fixed << setprecision(3) << maxFrequentLetterRate << "%)" << "\n";

    this->fileOut << setw(23) << "Least Frequent Letter: " << leastFrequentLetter << " ";
    this->fileOut << right << setw(3) << this->letterCounts[leastFrequentLetterIndex] << " ";
    this->fileOut << "(" << setw(7) << fixed << setprecision(3) << leastFrequentLetterRate << "%)" << "\n";

    // diff -s result.out solutions/aliceChapter1.out
}