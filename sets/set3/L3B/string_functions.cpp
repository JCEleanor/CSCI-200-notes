#include "string_functions.h"

#include <iostream>

using namespace std;

unsigned long string_length(const string STR)
{
    unsigned long result = -1;
    // FIXME: implicit conversion changes signedness: 'int' to 'unsigned long'
    result = STR.length(); // set result to the length of the string
    return result;
}

char string_char_at(const string STR, const int IDX)
{
    char result = (char)STR.at(IDX);
    // FIXME: implicit conversion changes signedness: 'const int' to 'size_type' (aka 'unsigned long')
    std::cout << "implement string_char_at(\"" << STR << "\", " << IDX << ")" << std::endl;
    return result;
}

string string_append(const string LEFT, const string RIGHT)
{
    string result = LEFT + RIGHT;
    // TODO 02: set result to the concatenation of strings LEFT and RIGHT
    std::cout << "implement string_append(\"" << LEFT << "\", \"" << RIGHT << "\")" << std::endl;
    return result;
}

string string_insert(const string STR, const string TO_INSERT, const int IDX)
{
    // NOTE: string& insert (size_t pos, const string& str, size_t subpos, size_t sublen);
    string result = STR;
    result.insert(static_cast<string::size_type>(IDX), TO_INSERT);
    // TODO 03: set result to the result of inserting a string into another
    return result;
}

size_t string_find(const string STR, const char C)
{
    size_t result = STR.find(C);
    std::cout << "implement string_find(\"" << STR << "\", '" << C << "')" << std::endl;
    return result;
}

string string_substring(const string STR, const int IDX, const int LEN)
{
    // NOTE: string substr (size_t pos = 0, size_t len = npos) const;
    string result = STR.substr(IDX, LEN);
    // TODO 05: set result to be a substring starting at index of given length
    return result;
}

string string_replace(const string STR, const string TEXT_TO_REPLACE, const string REPLACE_WITH)
{
    string result = STR;
    // return the first occurance
    size_t targetIndex = result.find(TEXT_TO_REPLACE);

    // cout << targetIndex << endl;
    if (targetIndex != string::npos)
    {
        result.replace(targetIndex, TEXT_TO_REPLACE.length(), REPLACE_WITH);
    }
    return result;
}

string string_first_word(const string STR)
{
    string result = STR;
    size_t firstSpace = STR.find(" ");
    if (firstSpace != string::npos)
    {
        result = STR.substr(0, firstSpace);
    }
    return result;
}

string string_remove_first_word(const string STR)
{
    string copy = STR;
    size_t firstSpace = STR.find(" ");
    string firstWord = STR.substr(0, firstSpace);

    copy.erase(0, firstWord.length() + 1);
    string result = copy;
    return result;
}

string string_second_word(const string STR)
{
    // step 1: remove first word
    string withoutFirstWord = string_remove_first_word(STR);
    // step 2: get the first (originally second word) word
    string secondWord = string_first_word(withoutFirstWord);

    string result = secondWord;
    return result;
}

string string_third_word(const string STR)
{
    string withoutFirst = string_remove_first_word(STR);
    string withoutSecond = string_remove_first_word(withoutFirst);
    string result = string_first_word(withoutSecond);
    return result;
}

string string_nth_word(const string STR, const int N)
{
    string result = STR;
    for (int i = 1; i < N; i++)
    {
        result = string_remove_first_word(result);
        if (result.empty())
        {
            return "";
        }
    }
    // TODO 11: set result to be the nth word from the string
    std::cout << "TODO: implement string_nth_word(\"" << STR << "\", " << N << ")" << std::endl;
    return result;
}

vector<string> string_tokenize(const string STR, const char DELIMINATOR)
{
    vector<string> result;
    // TODO 12: split the string by the given deliminator
    std::cout << "TODO: implement string_tokenize(\"" << STR << "\", '" << DELIMINATOR << "')" << std::endl;
    return result;
}

string string_substitute(const string STR, const char TARGET, const char REPLACEMENT)
{
    string result = STR;
    // TODO 13: set result to be the string with all instances of TARGET replaced
    std::cout << "TODO: implement string_substitute(\"" << STR << "\", '" << TARGET << "', '" << REPLACEMENT << "')" << std::endl;
    return result;
}

string string_to_lower(const string STR)
{
    string result = STR;
    // TODO 14: convert all characters to lower case
    std::cout << "TODO: implement string_to_lower(\"" << STR << "\")" << std::endl;
    return result;
}

string string_to_upper(const string STR)
{
    string result = STR;
    // TODO 15: convert all characters to upper case
    std::cout << "TODO: implement string_to_upper(\"" << STR << "\")" << std::endl;
    return result;
}

int string_compare(const string LHS, const string RHS)
{
    int result = 0;
    // TODO 16: compare LHS and RHS
    std::cout << "TODO: implement string_compare(\"" << LHS << "\", \"" << RHS << "\")" << std::endl;
    return result;
}