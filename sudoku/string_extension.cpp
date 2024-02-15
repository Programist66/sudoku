#include <iostream>
#include "string_extension.h"

using namespace std;

string letters = "ABCDEFGHI";

string multypli_word(int count, string word)
{
    string new_word;
    for (int i = 0; i < count; i++)
    {
        new_word += word;
    }
    return new_word;
}

bool is_Letter(char symbool)
{
    symbool = toupper(symbool);
    return int(symbool) >= 65 && int(symbool) <= 73;
}

string To_Upper(string word)
{
    string result = "";
    for (char ch : word)
    {
        if (is_Letter(ch))
        {
            result += toupper(ch);
        }
        else
        {
            result += ch;
        }
    }
    return result;
}

bool is_Digit(char symbool)
{
    return int(symbool) >= 49 && int(symbool) <= 57;
}

int letter_to_digit(char letter)
{
    int number = 0;
    for (char ch : letters)
    {
        if (ch == letter)
        {
            return number;
        }
        else
        {
            number++;
        }
    }
}