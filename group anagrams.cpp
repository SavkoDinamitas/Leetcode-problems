#include <iostream>
#include <bits-stdc++.h>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> groups;
    unordered_map<string, int> classification;
    int g = 1;
    for (int i = 0; i < strs.size(); i++)
    {
        string s = strs[i];
        sort(s.begin(), s.end());
        if (classification[s] == 0)
        {
            classification[s] = g++;
            groups.push_back({strs[i]});
        }
        else
        {
            groups[classification[s] - 1].push_back(strs[i]);
        }
    }
    return groups;
}