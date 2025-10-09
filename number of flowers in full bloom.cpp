#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int binarySearch(vector<pair<int, int>> &bloom, int time)
{
    int l = 0;
    int r = bloom.size() - 1;

    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (bloom[m].first <= time)
        {
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return r >= 0 ? bloom[r].second : 0;
}

vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people)
{
    int n = flowers.size();
    vector<int> start(n);
    vector<int> end(n);
    for (int i = 0; i < n; i++)
    {
        start[i] = flowers[i][0];
        end[i] = flowers[i][1];
    }
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    vector<pair<int, int>> bloom;
    int fl = 0;
    int s = 0;
    int e = 0;
    while (s < n || e < n)
    {
        int st = s < n ? start[s] : INT_MAX;
        int en = e < n ? end[e] : INT_MAX;
        if (st <= en)
        {
            fl++;
            bloom.push_back({st, fl});
            s++;
        }
        else
        {
            fl--;
            bloom.push_back({en + 1, fl});
            e++;
        }
    }

    vector<int> result;
    for (int time : people)
    {
        result.push_back(binarySearch(bloom, time));
    }
    return result;
}