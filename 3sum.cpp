#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    for (int i = 0; i < nums.size() - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k)
        {
            if (nums[j] + nums[k] < 0 - nums[i])
            {
                j++;
            }
            else if (nums[j] + nums[k] > 0 - nums[i])
            {
                k--;
            }
            else
            {
                if (result.size() == 0 || nums[i] != result[result.size() - 1][0] || nums[j] != result[result.size() - 1][1] || nums[k] != result[result.size() - 1][2])
                    result.push_back({nums[i], nums[j], nums[k]});
                j++;
            }
        }
    }
    return result;
}

int main()
{
}