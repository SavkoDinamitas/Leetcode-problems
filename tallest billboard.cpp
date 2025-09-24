#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int tallestBillboard(vector<int> &rods)
{
    int sum = 0;
    for (int i = 0; i < rods.size(); i++)
    {
        sum += rods[i];
    }
    vector<vector<int>> dp(rods.size() + 1, vector<int>(sum + 1, -1));
    dp[0][0] = 0;

    for (int i = 1; i <= rods.size(); i++)
    {
        int r = rods[i - 1];
        for (int d = 0; d <= sum; d++)
        {
            if (dp[i - 1][d] < 0)
                continue; // skip impossible

            // skip rod
            dp[i][d] = max(dp[i][d], dp[i - 1][d]);

            // add rod to taller side
            if (d + r <= sum)
            {
                dp[i][d + r] = max(dp[i][d + r], dp[i - 1][d]);
            }

            // put rod on the shorther side
            int newDiff = abs(d - r);
            int newHeight = dp[i - 1][d] + min(d, r);
            dp[i][newDiff] = max(dp[i][newDiff], newHeight);
        }
    }
    return dp[rods.size()][0];
}