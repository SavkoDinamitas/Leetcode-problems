#include <iostream>
#include <bits-stdc++.h>

using namespace std;

vector<int> findAnagrams(string s, string p)
{
    int n = p.size();
    if (n > s.size())
        return {};
    unordered_map<char, int> charFreq;
    for (char c : p)
    {
        charFreq[c]++;
    }
    unordered_map<char, int> window;
    int matched = 0;
    for (int i = 0; i < n - 1; i++)
    {
        char c = s[i];
        if (charFreq.count(c))
        {
            window[c]++;
            if (window[c] <= charFreq[c])
                matched++;
        }
    }
    vector<int> result;
    for (int i = n - 1; i < s.size(); i++)
    {
        char c = s[i];
        // add last
        if (charFreq.count(c))
        {
            window[c]++;
            if (window[c] <= charFreq[c])
                matched++;
        }

        if (matched == n)
            result.push_back(i - n + 1);

        // remove first
        char first = s[i - n + 1];
        if (charFreq.count(first))
        {
            window[first]--;
            if (window[first] < charFreq[first])
            {
                matched--;
            }
        }
    }

    return result;
}