#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maxIncreasingSubarrays(vector<int> &nums)
{
    int before = 0;
    int curr = 0;
    int maxi = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] < nums[i + 1])
        {
            curr++;
        }
        else
        {
            maxi = max(maxi, min(before, curr + 1));
            maxi = max(maxi, (curr + 1) / 2);
            before = curr + 1;
            curr = 0;
        }
    }
    maxi = max(maxi, min(before, curr + 1));
    maxi = max(maxi, (curr + 1) / 2);
    return maxi;
}