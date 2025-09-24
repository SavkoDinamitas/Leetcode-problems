#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int findTargetSumWays(vector<int> &nums, int target)
{
    int sum = 0;
    for (int num : nums)
        sum += num;

    if (target > sum || target < -sum)
        return 0;

    vector<vector<int>> dp(nums.size() + 1, vector<int>(2 * sum + 1, 0));
    dp[0][sum] = 1;

    for (int i = 1; i <= nums.size(); i++)
    {
        for (int j = 0; j <= 2 * sum; j++)
        {
            int minus = (j - nums[i - 1] >= 0) ? dp[i - 1][j - nums[i - 1]] : 0;
            int plus = (j + nums[i - 1] <= 2 * sum) ? dp[i - 1][j + nums[i - 1]] : 0;
            dp[i][j] = minus + plus;
        }
    }

    return dp[nums.size()][target + sum];
}
