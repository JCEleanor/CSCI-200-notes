#include "string_functions.h"

#include <iostream>

using namespace std;

unsigned long string_length(const string STR)
{
    unsigned long result = static_cast<unsigned long>(-1);
    result = STR.length(); // set result to the length of the string
    return result;
}

char string_char_at(const string STR, const int IDX)
{
    char result = (char)STR.at((size_t)IDX);
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
    string result = STR.substr((size_t)IDX, (size_t)LEN);
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

    return string_first_word(result);
}

vector<string> string_tokenize(const string STR, const char DELIMINATOR)
{
    vector<string> result;
    if (STR.empty())
    {
        result.push_back("");
        return result;
    }

    string current_token = "";

    for (size_t i = 0; i < STR.length(); i++)
    {
        if (STR[i] == DELIMINATOR)
        {
            result.push_back(current_token);
            current_token = "";
        }
        else
        {
            current_token += STR[i];
        }
    }

    result.push_back(current_token);

    return result;
}

string string_substitute(const string STR, const char TARGET, const char REPLACEMENT)
{
    string result = STR;

    for (size_t i = 0; i < result.length(); i++)
    {
        if (result[i] == TARGET)
        {
            result[i] = REPLACEMENT;
        }
    }

    return result;
}

string string_to_lower(const string STR)
{
    string result = STR;
    for (size_t i = 0; i < result.length(); i++)
    {
        result[i] = (char)tolower(result[i]);
    }
    return result;
}

string string_to_upper(const string STR)
{
    string result = STR;
    for (size_t i = 0; i < result.length(); i++)
    {
        result[i] = (char)toupper(result[i]);
    }
    return result;
}

int string_compare(const string LHS, const string RHS)
{
    int result = 0;

    size_t min_length = (LHS.length() < RHS.length()) ? LHS.length() : RHS.length();

    // all characters match up to min_length, compare lengths
    if (LHS.length() < RHS.length())
    {
        return -1;
    }
    else if (LHS.length() > RHS.length())
    {
        return 1;
    }

    for (size_t i = 0; i < min_length; i++)
    {
        if (LHS[i] < RHS[i])
        {
            return -1;
        }
        else if (LHS[i] > RHS[i])
        {
            return 1;
        }
    }

    return result;
}