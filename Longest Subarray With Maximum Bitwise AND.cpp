#include <iostream>
#include <bits/stdc++.h>

/*https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/description/?envType=daily-question&envId=2024-09-14*/

using namespace std;

int longestSubarray(vector<int> &nums)
{
    int count = 0;
    int res = 0;
    int maxEl = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > maxEl)
        {
            count = 1;
            maxEl = nums[i];
            res = 1;
            continue;
        }
        if (nums[i] == maxEl)
        {
            count++;
        }
        else
            count = 0;
        res = max(res, count);
    }
    return res;
}

int main()
{
}