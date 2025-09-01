#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int maximalSquare(vector<vector<char>> &matrix)
{
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()));
    int result = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (i == 0 || j == 0 || matrix[i][j] == '0')
                dp[i][j] = matrix[i][j];
            else
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
            result = max(result, dp[i][j]);
        }
    }
    return result * result;
}