#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int totalMoney(int n)
{
    int weeks = n / 7;
    int result = 28 * weeks + weeks * (weeks - 1) / 2 * 7;
    int curr = weeks + 1;
    for (int i = 0; i < n % 7; i++)
    {
        result += curr++;
    }
    return result;
}