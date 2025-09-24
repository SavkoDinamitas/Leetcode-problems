#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int knapsack(int W, vector<int> &val, vector<int> &wt)
{
    int n = val.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            if (j < wt[i - 1])
                dp[i][j] = dp[i - 1][j];
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wt[i - 1]] + val[i - 1]);
            }
        }
    }
    return dp[n][W];
}