#include <iostream>
#include <bits-stdc++.h>

using namespace std;

string minWindow(string s, string t)
{
    unordered_map<char, int> wordFreq;
    for (auto &w : t)
        wordFreq[w]++;

    int size = t.length();

    int l = 0, r = -1, count = 0;
    unordered_map<char, int> window;
    int left = 0, right = INT_MAX;
    while (r < (int)s.size() - 1 || count == size)
    {
        if (count < size)
        {
            r++;
            if (wordFreq.count(s[r]))
            {
                window[s[r]]++;
                if (window[s[r]] <= wordFreq[s[r]])
                    count++;
            }
        }
        if (count == size)
        {
            if (r - l < right - left)
            {
                right = r;
                left = l;
            }
            if (wordFreq.count(s[l]))
            {
                window[s[l]]--;
                if (window[s[l]] < wordFreq[s[l]])
                    count--;
            }
            l++;
        }
    }
    return left || right != INT_MAX ? s.substr(left, right - left + 1) : "";
}