#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// missing some edgecase...
int maxDistinctElements(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int largest = INT_MIN;
    int result = 1;
    int i = 1;
    while (i < nums.size())
    {
        if (nums[i] != nums[i - 1])
        {
            largest = max(largest + 1, nums[i] - k + 1);
            result++;
            i++;
            continue;
        }
        int curr = max(largest, nums[i] - k + 1);
        while (i < nums.size() && nums[i] == nums[i - 1])
        {
            if (curr <= nums[i] + k)
            {
                result++;
            }
            curr++;
            i++;
        }
        largest = curr;
    }
    return result;
}

int maxDistinctElements(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int assign = INT_MIN;
    int res = 0;
    for (int num : nums)
    {
        if (assign <= num + k)
        {
            res++;
            assign = max(assign + 1, num - k);
        }
    }
    return res;
}