#include <iostream>
#include <bits-stdc++.h>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        if (map[nums[i]] != 0)
        {
            return {map[nums[i]] - 1, i};
        }
        map[target - nums[i]] = i + 1;
    }
    return {};
}