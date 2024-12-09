#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_set<char> ponavljanje;
    int len = 0;
    int i = 0;
    for (int j = 0; j < s.length(); j++)
    {
        if (ponavljanje.insert(s[j]).second)
        {
            len = max(len, j - i + 1);
        }
        else
        {
            while (s[i] != s[j])
            {
                ponavljanje.erase(s[i]);
                i++;
            }
            i++;
        }
    }
    return len;
}

int main()
{
}