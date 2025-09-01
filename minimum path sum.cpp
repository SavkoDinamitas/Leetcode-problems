#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = grid[i][j];
                continue;
            }
            int up = i > 0 ? dp[i - 1][j] : INT_MAX;
            int left = j > 0 ? dp[i][j - 1] : INT_MAX;
            dp[i][j] = grid[i][j] + min(up, left);
        }
    }
    return dp.back().back();
}