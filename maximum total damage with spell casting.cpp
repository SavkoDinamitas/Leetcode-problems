#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &power, int ind)
{
    int l = 0;
    int r = power.size() - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (power[m] < ind)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return r;
}

long long maximumTotalDamage(vector<int> &power)
{
    sort(power.begin(), power.end());
    unordered_map<int, int> freq;
    for (int num : power)
    {
        freq[num]++;
    }
    vector<long long> dp(power.size());
    dp.push_back(0);
    for (int i = 1; i <= power.size(); i++)
    {
        int idx = binarySearch(power, power[i - 1] - 2);
        dp[i] =
            max(dp[i - 1], dp[idx + 1] + (long long)power[i - 1] * freq[power[i - 1]]);
    }
    return dp.back();
}

// without binary search, a bit optimized, still O(n log n) because of sort
long long maximumTotalDamage1(vector<int> &power)
{
    sort(power.begin(), power.end());
    unordered_map<int, int> freq;
    for (int num : power)
    {
        freq[num]++;
    }
    vector<long long> dp(power.size() + 1);
    dp[0] = 0;
    int last = 0;
    for (int i = 1; i <= power.size(); i++)
    {
        while (power[last + 1] < power[i - 1] - 2)
        {
            last++;
        }
        dp[i] = max(dp[i - 1], dp[last] + (long long)power[i - 1] * freq[power[i - 1]]);
    }
    return dp.back();
}

int main()
{
    vector<int> power = {1, 1, 3, 4};
    cout << endl
         << maximumTotalDamage1(power);
}