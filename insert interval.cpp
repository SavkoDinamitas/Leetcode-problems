#include <iostream>
#include <bits-stdc++.h>

using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    int pos = -1;
    for (int i = 0; i < intervals.size(); i++)
    {
        if (intervals[i][0] > newInterval[0])
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
        intervals.push_back(newInterval);
    else
    {
        intervals.insert(intervals.begin() + pos, newInterval);
    }
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