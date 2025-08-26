#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int maxSubarraySumCircular(vector<int> &nums)
{
    if (nums.empty())
        return 0;
    int currMax = 0, maxSum = nums[0];
    int currMin = 0, minSum = nums[0];
    int sum = 0;

    for (int n : nums)
    {
        currMax = max(n, currMax + n);
        maxSum = max(maxSum, currMax);

        currMin = min(n, currMin + n);
        minSum = min(minSum, currMin);

        sum += n;
    }

    return sum == minSum ? maxSum : max(maxSum, sum - minSum);
}