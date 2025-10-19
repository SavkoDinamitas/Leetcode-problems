#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string findLexSmallestString(string s, int a, int b)
{
    queue<string> q;
    unordered_set<string> set;
    set.insert(s);
    q.push(s);
    string smallest = s;
    while (!q.empty())
    {
        string top = q.front();
        q.pop();
        if (smallest > top)
            smallest = top;

        string rotate = "";
        rotate += top.substr(b);
        rotate += top.substr(0, b);
        if (set.insert(rotate).second)
        {
            q.push(rotate);
        }
        for (int i = 1; i < top.size(); i += 2)
        {
            top[i] = (top[i] - '0' + a) % 10 + '0';
        }
        if (set.insert(top).second)
        {
            q.push(top);
        }
    }
    return smallest;
}

// optimized
string findLexSmallestString(string s, int a, int b)
{
    string smallest = s;
    int n = s.size();
    int cycle = gcd(n, b);

    for (int rot = 0; rot < n; rot += cycle)
    {
        string rotated = s.substr(rot) + s.substr(0, rot);

        for (int t = 0; t < 10; t++)
        {
            string added = rotated;
            for (int i = 1; i < n; i += 2)
                added[i] = ((added[i] - '0' + a * t) % 10) + '0';

            if (b % 2 == 1)
            {
                for (int t2 = 0; t2 < 10; t2++)
                {
                    string added2 = added;
                    for (int i = 0; i < n; i += 2)
                        added2[i] = ((added2[i] - '0' + a * t2) % 10) + '0';
                    smallest = min(smallest, added2);
                }
            }
            else
            {
                smallest = min(smallest, added);
            }
        }
    }
    return smallest;
}

int main()
{
    cout << findLexSmallestString("74", 5, 1);
}