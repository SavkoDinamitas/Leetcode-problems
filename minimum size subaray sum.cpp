#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int i = 0;
    int len = INT_MAX;
    int sum = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        sum += nums[j];
        while (sum >= target)
        {
            len = min(len, j - i + 1);
            sum -= nums[i];
            i++;
        }
    }
    if (len == INT_MAX)
        return 0;
    return len;
}

int main()
{
}