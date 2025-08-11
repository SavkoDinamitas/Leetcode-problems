#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int findMinArrowShots(vector<vector<int>> &points)
{
    sort(points.begin(), points.end(),
         [](const vector<int> &a, const vector<int> &b)
         {
             return a[0] < b[0];
         });
    int result = 1;
    pair<int, int> interval = make_pair(points[0][0], points[0][1]);
    for (int i = 1; i < points.size(); i++)
    {
        if (points[i][0] <= interval.second)
        {
            interval.second = min(interval.second, points[i][1]);
        }
        else
        {
            result++;
            interval = make_pair(points[i][0], points[i][1]);
        }
    }
    return result;
}