#include <iostream>
#include <bits-stdc++.h>

using namespace std;

// brute force
vector<int> smallestRange(vector<vector<int>> &nums)
{
    vector<int> indices(nums.size(), 0);
    vector<int> range = {INT_MIN, INT_MAX};
    while (true)
    {
        // look for max and min in arrays
        int indexMin = 0, indexMax = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i][indices[i]] < nums[indexMin][indices[indexMin]])
            {
                indexMin = i;
            }
            if (nums[i][indices[i]] > nums[indexMax][indices[indexMax]])
            {
                indexMax = i;
            }
        }
        int low = nums[indexMin][indices[indexMin]];
        int high = nums[indexMax][indices[indexMax]];
        if ((range[0] == INT_MIN || range[1] - range[0] > high - low) || (range[1] - range[0] == high - low && low < range[0]))
        {
            range[0] = low;
            range[1] = high;
        }
        // if I used whole array, end the traverse
        indices[indexMin]++;
        if (nums[indexMin].size() <= indices[indexMin])
            break;
    }
    return range;
}

// optimization
vector<int> smallestRange(vector<vector<int>> &nums)
{
    vector<int> indices(nums.size(), 0);
    vector<int> range = {INT_MIN, INT_MAX};

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
    int currMax = INT_MIN;

    // insert first elements into a queue
    for (int i = 0; i < nums.size(); i++)
    {
        minHeap.push({nums[i][0], i});
        currMax = max(currMax, nums[i][0]);
    }

    while (true)
    {
        auto [value, index] = minHeap.top();
        minHeap.pop();
        if ((range[0] == INT_MIN || range[1] - range[0] > currMax - value) || (range[1] - range[0] == currMax - value && value < range[0]))
        {
            range[0] = value;
            range[1] = currMax;
        }
        if (indices[index] == nums[index].size() - 1)
        {
            return range;
        }
        currMax = max(currMax, nums[index][++indices[index]]);
        minHeap.push({nums[index][indices[index]], index});
    }
}