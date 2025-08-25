#include <iostream>
#include <bits-stdc++.h>

using namespace std;

vector<vector<int>> result;

void permutate(vector<int> &nums, vector<bool> &used, vector<int> &perm)
{
    if (perm.size() == nums.size())
    {
        result.push_back(perm);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (!used[i])
        {
            perm.push_back(i);
            used[i] = true;
            permutate(nums, used, perm);
            perm.pop_back();
            used[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<bool> used(nums.size(), false);
    vector<int> perm;
    permutate(nums, used, perm);
    return result;
}