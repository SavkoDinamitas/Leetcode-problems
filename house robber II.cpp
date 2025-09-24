#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int rob(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    if (nums.empty())
        return 0;
    int curr = nums[0];
    int prev = 0;
    for (int i = 1; i < nums.size() - 1; i++)
    {
        int x = curr;
        curr = max(curr, prev + nums[i]);
        prev = x;
    }
    int curr1 = nums[1];
    prev = 0;
    for (int i = 2; i < nums.size(); i++)
    {
        int x = curr1;
        curr1 = max(curr1, prev + nums[i]);
        prev = x;
    }
    return max(curr1, curr);
}