#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int climbStairs(int n)
{
    int prev = 1;
    int curr = 1;
    if (n < 2)
        return 1;
    for (int i = 2; i <= n; i++)
    {
        int p = curr;
        curr = curr + prev;
        prev = p;
    }
    return curr;
}