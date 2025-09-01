#include <iostream>
#include <bits-stdc++.h>

using namespace std;

// O(n^2) memory
int minimumTotal(vector<vector<int>> &triangle)
{
    if (triangle.empty())
        return 0;
    vector<vector<int>> dp(triangle.size());
    dp[0].push_back(triangle[0][0]);
    if (triangle.size() == 1)
        return dp[0][0];
    int result = INT_MAX;
    for (int i = 1; i < triangle.size(); i++)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            int left = j > 0 ? dp[i - 1][j - 1] : INT_MAX;
            int right = j < triangle[i - 1].size() ? dp[i - 1][j] : INT_MAX;
            dp[i].push_back(min(left, right) + triangle[i][j]);
            if (i == triangle.size() - 1)
                result = min(result, dp[i][j]);
        }
    }
    return result;
}

// O(n) memory
int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<int> dp = triangle.back();
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
        }
    }
    return dp[0];
}