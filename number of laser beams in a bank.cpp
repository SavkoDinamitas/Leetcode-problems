#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int numberOfBeams(vector<string> &bank)
{
    int result = 0;
    int last = 0;
    for (string s : bank)
    {
        int curr = 0;
        for (char c : s)
        {
            curr += c - '0';
        }
        if (last != 0 && curr != 0)
        {
            result += last * curr;
            last = curr;
        }
        else if (!last && curr != 0)
        {
            last = curr;
        }
    }
    return result;
}