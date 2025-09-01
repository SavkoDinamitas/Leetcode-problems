#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int maxProfit(int k, vector<int> &prices)
{
    vector<vector<int>> dp(k + 1, vector<int>(prices.size() + 1, 0));
    int result = 0;
    for (int i = 1; i <= k; i++)
    {
        int minPrice = INT_MAX;
        for (int j = 1; j <= prices.size(); j++)
        {
            minPrice = min(minPrice, prices[j - 1] - dp[i - 1][j - 1]);
            dp[i][j] = max(dp[i][j - 1], prices[j - 1] - minPrice);
            result = max(result, dp[i][j]);
        }
    }
    return result;
}