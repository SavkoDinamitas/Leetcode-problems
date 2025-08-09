#include <iostream>
#include <bits-stdc++.h>

using namespace std;

vector<string> split(const string &str, char delimiter)
{
    vector<string> tokens;
    stringstream ss(str);
    string token;

    while (getline(ss, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

bool wordPattern(string pattern, string s)
{
    vector<string> words = split(s, ' ');
    unordered_map<char, string> dictionary;
    unordered_set<string> values;
    if (pattern.length() != words.size())
        return false;
    for (int i = 0; i < pattern.length(); i++)
    {
        if (dictionary[pattern[i]] == "")
        {
            if (!values.insert(words[i]).second)
                return false;
            dictionary[pattern[i]] = words[i];
        }
        else if (dictionary[pattern[i]] != words[i])
            return false;
    }
    return true;
}