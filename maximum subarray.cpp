#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int maxSubArray(vector<int> &nums)
{
    if (nums.empty())
        return 0;
    int result = nums[0];
    vector<int> dp(nums.size() + 1);
    dp[0] = 0;
    for (int i = 1; i <= nums.size(); i++)
    {
        dp[i] = max(nums[i - 1], nums[i - 1] + dp[i - 1]);
        result = max(result, dp[i]);
    }
    return result;
}