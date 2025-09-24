#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int minSteps(int n)
{
    vector<int> dp(n + 1);
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (i % j == 0)
            {
                dp[i] = dp[j] + i / j;
                break;
            }
        }
    }
    return dp[n];
}

int minSteps(int n)
{
    int result = 0;
    for (int d = 2; d * d <= n; d++)
    {
        while (n % d == 0)
        {
            n /= d;
            result += d;
        }
    }
    return n > 1 ? result + n : result;
}