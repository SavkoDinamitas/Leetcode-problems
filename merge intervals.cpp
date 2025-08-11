#include <iostream>
#include <bits-stdc++.h>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(),
         [](const vector<int> &a, const vector<int> &b)
         {
             return a[0] < b[0];
         });

    vector<vector<int>> merged;
    merged.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
    {
        if (merged.back()[1] >= intervals[i][0])
        {
            merged.back()[1] = max(intervals[i][1], merged.back()[1]);
        }
        else
        {
            merged.push_back(intervals[i]);
        }
    }
    return merged;
}