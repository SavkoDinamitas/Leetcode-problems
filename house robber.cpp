#include <bits-stdc++.h>
#include <iostream>

using namespace std;

int rob(vector<int> &nums)
{
    int prev = 0;
    int curr = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        int p = curr;
        curr = max(curr, prev + nums[i]);
        prev = p;
    }
    return curr;
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = nums[0];
    for (int i = 2; i < n + 1; i++)
    {
        dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
    }
    return dp[n];
}

int main()
{
}