#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int trap(vector<int> &height)
{
    vector<int> maxH(height.size());
    maxH[0] = height[0];
    for (int i = 1; i < height.size(); i++)
    {
        maxH[i] = max(maxH[i - 1], height[i]);
    }
    int res = 0;
    int curr = height.back();
    for (int i = height.size() - 1; i >= 0; i--)
    {
        curr = max(curr, height[i]);
        res += min(curr, maxH[i]) - height[i];
    }
    return res;
}