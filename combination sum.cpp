#include <iostream>
#include <bits-stdc++.h>

using namespace std;

vector<vector<int>> result;

// backtracking solution
void combine(vector<int> &candidates, int target, int sum, vector<int> &comb)
{
    if (sum == target)
    {
        result.push_back(comb);
        return;
    }
    if (sum > target)
        return;
    for (int c : candidates)
    {
        if (comb.size() == 0 || comb.back() <= c)
        {
            comb.push_back(c);
            combine(candidates, target, sum + c, comb);
            comb.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<int> comb;
    combine(candidates, target, 0, comb);
    return result;
}

void reconstruct(vector<vector<int>> &dp, int pos, vector<int> &comb, vector<vector<int>> &result)
{
    if (pos == 0)
    {
        result.push_back(comb);
        return;
    }

    for (int c : dp[pos])
    {
        if (comb.size() == 0 || comb.back() <= c)
        {
            comb.push_back(c);
            reconstruct(dp, pos - c, comb, result);
            comb.pop_back();
        }
    }
}

// dp solution
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> dp(target + 1);
    for (int i = 0; i <= target; i++)
    {
        for (int c : candidates)
        {
            if (c == i)
                dp[i].push_back(c);
            if (c < i && dp[i - c].size() != 0)
                dp[i].push_back(c);
        }
    }
    vector<vector<int>> result;
    vector<int> comb;
    reconstruct(dp, target, comb, result);
    return result;
}