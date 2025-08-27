#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    // min heap
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(nums[i]);
    }
    for (int i = k; i < nums.size(); i++)
    {
        pq.push(nums[i]);
        pq.pop();
    }
    return pq.top();
}
// quick select
int findKthLargest(vector<int> &nums, int k)
{
    int left = 0, right = nums.size() - 1, target = nums.size() - k;
    while (left <= right)
    {
        int pivot = nums[right];
        int i = left;
        for (int j = left; j < right; j++)
        {
            if (nums[j] <= pivot)
            {
                swap(nums[i++], nums[j]);
            }
        }
        swap(nums[right], nums[i]);

        if (i == target)
            return nums[i];
        if (i < target)
            left = i + 1;
        else
            right = i - 1;
    }
}