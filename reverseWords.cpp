#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string reverseWords(string s)
{
    string res = "";
    int start = -1;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            if (start != -1)
            {
                res += s.substr(i + 1, start - i) + ' ';
                start = -1;
            }
            else
                continue;
        }
        else if (s[i + 1] == ' ' || i == s.length() - 1)
        {
            start = i;
        }
    }
    if (s[0] != ' ')
    {
        res += s.substr(0, start) + ' ';
    }
    res.erase(res.length() - 1);
    return res;
}

int main()
{
    cout << reverseWords("ide mile preko polja  ");
}