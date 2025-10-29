#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int smallestNumber(int n)
{
    int i = 1;
    while (i <= n)
    {
        i *= 2;
    }
    return i - 1;
}