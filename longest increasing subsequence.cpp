#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int lis(vector<int> &nums)
{
    vector<int> dp(nums.size());
    dp[0] = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        int maxLen = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[i] > nums[j])
                maxLen = max(maxLen, dp[j]);
        }
        dp[i] = maxLen + 1;
    }
    int maxi = -1;
    for (int i = 0; i < dp.size(); i++)
    {
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}

int binarySearch(vector<int> &nums, int target)
{
    int l = 0;
    int r = nums.size() - 1;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (nums[mid] >= target)
            r = mid;
        else
        {
            l = mid + 1;
        }
    }
    return l;
}

int lis2(vector<int> &nums)
{
    vector<int> xd;
    xd.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {
        if (xd[xd.size() - 1] < nums[i])
        {
            xd.push_back(nums[i]);
        }
        else
        {
            xd[binarySearch(xd, nums[i])] = nums[i];
        }
    }
    return xd.size();
}

int main()
{
    vector<int> nums = {4, 10, 4, 3, 8, 9};
    cout << endl
         << lis2(nums);
}