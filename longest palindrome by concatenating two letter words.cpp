#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int longestPalindrome(vector<string> &words)
{
    unordered_map<string, int> map;
    int s = 0;
    int pairs = 0;
    for (int i = 0; i < words.size(); i++)
    {
        bool same = words[i][0] == words[i][1];
        if (map[words[i]] > 0)
        {
            if (same)
                s--;
            pairs++;
            map[words[i]]--;
        }
        else
        {
            if (same)
                s++;
            string str = "";
            str += words[i][1];
            str += words[i][0];
            map[str]++;
        }
    }
    return s ? pairs * 4 + 2 : pairs * 4;
}