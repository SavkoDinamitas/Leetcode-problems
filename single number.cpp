#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int singleNumber(vector<int> &nums)
{
    int result = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        result ^= nums[i];
    }
    return result;
}