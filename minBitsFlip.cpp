#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*https://leetcode.com/problems/minimum-bit-flips-to-convert-number/submissions/1386986046/?envType=daily-question&envId=2024-09-11*/

int minBitFlips(int start, int goal)
{
    vector<int> bins;
    vector<int> bing;
    int mul = 1;
    while (start > 0)
    {
        bins.push_back(start % 2);
        start /= 2;
    }
    mul = 1;
    while (goal > 0)
    {
        bing.push_back(goal % 2);
        goal /= 2;
    }

    int ss = bins.size();
    int gs = bing.size();
    if (gs > ss)
    {
        for (int i = 0; i < gs - ss; i++)
        {
            bins.push_back(0);
        }
    }

    if (ss > gs)
    {
        for (int i = 0; i < ss - gs; i++)
        {
            bing.push_back(0);
        }
    }

    int result = 0;
    for (int i = 0; i < bins.size(); i++)
    {
        if (bins[i] != bing[i])
            result++;
    }
    return result;
}

int minBitFlips2(int start, int goal)
{
    int result = 0;
    while (start > 0 && goal > 0)
    {
        if (start % 2 != goal % 2)
            result++;
        start /= 2;
        goal /= 2;
    }
    while (goal > 0)
    {
        if (goal % 2)
            result++;
        goal /= 2;
    }

    while (start > 0)
    {
        if (start % 2)
            result++;
        start /= 2;
    }
}

int main()
{
}