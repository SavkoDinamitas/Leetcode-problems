#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// my sliding window solution O(nums[n-1] - nums[0])
int maxFrequencyX(vector<int> &nums, int k, int numOperations)
{
    sort(nums.begin(), nums.end());
    unordered_map<int, int> freq;
    for (int num : nums)
    {
        freq[num]++;
    }
    int l = 0;
    int r = 0;
    int maxRes = 0;
    for (int element = nums[0]; element <= nums.back(); element++)
    {
        while (nums[l] < element - k)
        {
            l++;
        }
        while (r + 1 < nums.size() && nums[r + 1] - k <= element)
        {
            r++;
        }
        if (freq.count(element))
            maxRes = max(maxRes, min(r - l + 1, numOperations + freq[element]));
        else
            maxRes = max(maxRes, min(r - l + 1, numOperations));
    }
    return maxRes;
}

int first_lower(vector<int> &nums, int x)
{
    int l = 0;
    int r = nums.size();

    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (nums[m] < x)
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

int first_greater(vector<int> &nums, int x)
{
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (nums[m] <= x)
        {
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return l;
}

int maxFrequency(vector<int> &nums, int k, int numOperations)
{
    sort(nums.begin(), nums.end());
    unordered_map<int, int> freq;
    for (int num : nums)
    {
        freq[num]++;
    }
    int res = 0;
    for (int i = nums[0]; i <= nums.back(); i++)
    {
        int l = first_lower(nums, i - k);
        int r = first_greater(nums, i + k);
        res = max(res, min(numOperations + freq[i], r - l - 1));
    }
    return res;
}

int main()
{
    vector<int> nums = {1, 4, 5};
    cout << maxFrequency(nums, 1, 2);
}