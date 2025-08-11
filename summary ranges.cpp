#include <iostream>
#include <bits-stdc++.h>

using namespace std;

vector<string> summaryRanges(vector<int> &nums)
{
    vector<string> result;
    for (int i = 0; i < nums.size(); i++)
    {
        string range = "";
        range += to_string(nums[i]);
        bool entered = false;
        while (i + 1 < nums.size() && nums[i + 1] == nums[i] + 1)
        {
            entered = true;
            i++;
        }
        if (entered)
        {
            range += "->" + to_string(nums[i]);
        }
        result.push_back(range);
    }
    return result;
}