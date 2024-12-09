#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> output(n, 1);
    int left = nums[0];
    for (int i = 1; i < n; i++)
    {
        output[i] *= left;
        left *= nums[i];
    }
    int right = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        output[i] *= right;
        right *= nums[i];
    }
    return output;
}

int main()
{
}