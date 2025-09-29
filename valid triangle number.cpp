#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int triangleNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int result = 0;
    for (int k = nums.size() - 1; k >= 2; k--)
    {
        int i = 0, j = k - 1;
        while (i < j)
        {
            if (nums[i] + nums[j] > nums[k])
            {
                result += j - i;
                j--;
            }
            else
                i++;
        }
    }
    return result;
}