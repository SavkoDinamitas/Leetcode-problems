#include <bits-stdc++.h>
#include <iostream>

using namespace std;

bool wordBreak(string s, vector<string> &wordDict)
{
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    unordered_set<string> set(wordDict.begin(), wordDict.end());
    int maxLen = 0;
    for (int i = 0; i < wordDict.size(); i++)
    {
        maxLen = max(maxLen, (int)wordDict[i].size());
    }
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j >= max(i - maxLen, 0); j--)
        {
            if (dp[j] && set.count(s.substr(j, i - j + 1)))
            {
                dp[i + 1] = true;
                break;
            }
        }
    }
    return dp[s.size()];
}

bool wordBreak(string s, vector<string> &wordDict)
{
    vector<bool> dp(s.length() + 1, false);
    dp[0] = true;
    for (int i = 1; i < s.length() + 1; i++)
    {
        for (int j = 0; j < wordDict.size(); j++)
        {
            int wl = wordDict[j].length();
            int start = i - wl;
            if (start >= 0 && dp[start] && s.substr(start, wl) == wordDict[j])
                dp[i] = true;
        }
    }
    return dp[s.length()];
}

int main()
{
}