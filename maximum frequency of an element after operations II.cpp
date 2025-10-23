#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maxFrequency(vector<int> &nums, int k, int numOperations)
{
    unordered_map<int, int> freq;
    int maxi = 0;
    for (int num : nums)
    {
        freq[num]++;
        maxi = max(maxi, freq[num]);
    }
    if (k == 0 || numOperations == 0)
        return maxi;
    vector<int> possible;
    for (int i = 0; i < nums.size(); i++)
    {
        possible.push_back(nums[i] - k);
        possible.push_back(nums[i]);
        possible.push_back(nums[i] + k);
    }
    sort(nums.begin(), nums.end());
    sort(possible.begin(), possible.end());
    int l = 0;
    int r = 0;
    int maxRes = 0;
    for (int i = 0; i < possible.size(); i++)
    {
        while (nums[l] < possible[i] - k)
        {
            l++;
        }
        while (r + 1 < nums.size() && nums[r + 1] - k <= possible[i])
        {
            r++;
        }
        if (freq.count(possible[i]))
            maxRes = max(maxRes,
                         min(r - l + 1, numOperations + freq[possible[i]]));
        else
            maxRes = max(maxRes, min(r - l + 1, numOperations));
    }
    return maxRes;
}