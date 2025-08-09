#include <iostream>
#include <bits-stdc++.h>

using namespace std;

bool isAnagram(string s, string t)
{
    unordered_map<char, int> mapica;
    for (int i = 0; i < s.size(); i++)
    {
        mapica[s[i]]++;
    }
    for (int i = 0; i < t.size(); i++)
    {
        if (mapica[t[i]] == 0)
            return false;
        mapica[t[i]]--;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (mapica[s[i]] != 0)
            return false;
    }
    return true;
}