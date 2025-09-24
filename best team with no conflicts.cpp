#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int bestTeamScore(vector<int> &scores, vector<int> &ages)
{
    vector<pair<int, int>> arr;
    int n = scores.size();
    for (int i = 0; i < n; i++)
    {
        arr.push_back({ages[i], scores[i]});
    }
    sort(arr.begin(), arr.end());

    int result = arr[0].second;
    vector<int> dp(n);
    dp[0] = result;
    for (int i = 1; i < n; i++)
    {
        int maxres = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j].second <= arr[i].second)
            {
                maxres = max(dp[j], maxres);
            }
        }
        dp[i] = maxres + arr[i].second;
        result = max(result, dp[i]);
    }
    return result;
}