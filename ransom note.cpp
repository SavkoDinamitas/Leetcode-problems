#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    unordered_map<char, int> letters;
    for (int i = 0; i < magazine.length(); i++)
    {
        letters[magazine[i]]++;
    }
    for (int i = 0; i < ransomNote.length(); i++)
    {
        if (letters[ransomNote[i]] <= 0)
        {
            return false;
        }
        letters[ransomNote[i]]--;
    }
    return true;
}