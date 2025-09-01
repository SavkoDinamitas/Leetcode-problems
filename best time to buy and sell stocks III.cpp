#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int maxProfit(vector<int> &prices)
{
    vector<int> dp(prices.size());
    dp[0] = 0;
    int curr = prices[0];
    for (int i = 1; i < prices.size(); i++)
    {
        dp[i] = max(dp[i - 1], prices[i] - curr);
        curr = min(curr, prices[i]);
    }
    int result = 0;
    curr = prices.back();
    int profit = 0;
    for (int i = prices.size() - 1; i > 0; i--)
    {
        profit = max(profit, curr - prices[i]);
        result = max(result, profit + dp[i - 1]);
        curr = max(curr, prices[i]);
    }
    return max(result, dp.back());
}

// shorter solution
int maxProfit(vector<int> &prices)
{
    int buy1 = INT_MAX, profit1 = 0;
    int buy2 = INT_MAX, profit2 = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        buy1 = min(buy1, prices[i]);
        profit1 = max(profit1, prices[i] - buy1);

        buy2 = min(buy2, prices[i] - profit1);
        profit2 = max(profit2, prices[i] - buy2);
    }
    return profit2;
}