#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool hasSameDigits(string s)
{
    int last = s[s.length() - 1] - '0';
    int res = 0;
    while (s.length() > 2)
    {
        string news = "";
        for (int i = 0; i < s.length() - 1; i++)
        {
            news += '0' + (s[i] + s[i + 1] - 2 * '0') % 10;
        }
        s = news;
    }

    return s[0] == s[1];
}