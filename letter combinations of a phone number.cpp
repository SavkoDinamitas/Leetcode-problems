#include <iostream>
#include <bits-stdc++.h>

using namespace std;

vector<string> result;
vector<vector<char>> letters = {{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};

void generateCombinations(const string &digits, string word)
{
    if (word.length() == digits.length())
    {
        result.push_back(word);
        return;
    }
    int i = word.length();
    for (char c : letters[digits[i] - '0' - 2])
    {
        generateCombinations(digits, word + c);
    }
}

vector<string> letterCombinations(string digits)
{
    generateCombinations(digits, "");
    return result;
}