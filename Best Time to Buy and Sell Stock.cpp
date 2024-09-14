#include <iostream>
#include <bits/stdc++.h>
/*https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/?envType=study-plan-v2&envId=top-interview-150*/

using namespace std;

int maxProfit(vector<int> &prices)
{
    int maxi[prices.size()];
    maxi[prices.size() - 1] = prices[prices.size() - 1];
    for (int i = prices.size() - 2; i >= 0; i--)
    {
        maxi[i] = max(prices[i], maxi[i + 1]);
    }

    int res = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        res = max(res, maxi[i] - prices[i]);
    }
    return res;
}

int maxProfitBetter(vector<int> &prices)
{
    int mini = INT_MAX;
    int res = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        mini = min(mini, prices[i]);
        res = max(res, prices[i] - mini);
    }
    return res;
}

/*https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/?envType=study-plan-v2&envId=top-interview-150*/

int maxProfitII(vector<int> &prices)
{
    int profit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > prices[i - 1])
        {
            profit += prices[i] - prices[i - 1];
        }
    }
    return profit;
}

int main()
{
}