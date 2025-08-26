#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int lower(vector<int> &nums, int target)
{
    int l = 0;
    int r = nums.size() - 1;

    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (nums[m] < target)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return (l < nums.size() && nums[l] == target) ? l : -1;
}

int higher(vector<int> &nums, int target)
{
    int l = 0;
    int r = nums.size() - 1;

    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (nums[m] <= target)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return (r >= 0 && nums[r] == target) ? r : -1;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    if (nums.empty())
        return {-1, -1};
    return {lower(nums, target), higher(nums, target)};
}