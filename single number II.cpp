#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int singleNumber(vector<int> &nums)
{
    int result = 0;
    for (int i = 0; i < 32; i++)
    {
        int count = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            count += (nums[j] >> i) & 1;
        }
        if (count % 3 != 0)
            result |= 1 << i;
    }
    return result;
}

// impossible level solution
int singleNumber(vector<int> &nums)
{
    int ones = 0;
    int twos = 0;
    for (int num : nums)
    {
        twos |= ones & num;
        ones ^= num;
        int mask = ~(ones & twos);
        ones &= mask;
        twos &= mask;
    }
    return ones;
}