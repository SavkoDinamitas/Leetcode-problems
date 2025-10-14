#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool hasIncreasingSubarrays(vector<int> &nums, int k)
{
    bool before = false;
    int inc = 1;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] < nums[i + 1])
        {
            inc++;
        }
        else
        {
            if (inc >= 2 * k)
                return true;
            if (inc >= k)
            {
                if (!before)
                    before = true;
                else
                    return true;
            }
            else
                before = false;
            inc = 1;
        }
    }
    if (inc >= 2 * k || (inc >= k && before))
        return true;
    return false;
}