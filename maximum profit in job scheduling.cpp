#include <iostream>
#include <bits-stdc++.h>

using namespace std;

// MLE if end times values are large
int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
{
    vector<tuple<int, int, int>> joined;
    for (int i = 0; i < startTime.size(); i++)
    {
        joined.push_back({endTime[i], startTime[i], profit[i]});
    }
    sort(joined.begin(), joined.end());

    int e = 0;
    vector<int> dp(get<0>(joined.back()) + 1);
    for (int i = 1; i < dp.size(); i++)
    {
        int curr = dp[i - 1];
        while (e < endTime.size() && get<0>(joined[e]) <= i)
        {
            auto [end, start, profit] = joined[e++];
            int p = profit + dp[start];
            curr = max(curr, p);
        }
        dp[i] = curr;
    }
    return dp.back();
}

// optimal solution
int binarySearch(vector<tuple<int, int, int>> &joined, int startTime)
{
    int l = 0;
    int r = joined.size();

    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (get<0>(joined[m]) <= startTime)
            l = m + 1;
        else
            r = m - 1;
    }
    return r;
}

int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
{
    vector<tuple<int, int, int>> joined;
    for (int i = 0; i < startTime.size(); i++)
    {
        joined.push_back({endTime[i], startTime[i], profit[i]});
    }
    sort(joined.begin(), joined.end());

    vector<int> dp(startTime.size());
    dp[0] = get<2>(joined[0]);
    for (int i = 1; i < dp.size(); i++)
    {
        auto [end, start, profit] = joined[i];
        int index = binarySearch(joined, start);
        int p = index != -1 ? dp[index] + profit : profit;
        dp[i] = max(dp[i - 1], p);
    }
    return dp.back();
}