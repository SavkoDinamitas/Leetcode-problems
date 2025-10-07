#include <iostream>
#include <bits-stdc++.h>

using namespace std;

class TimeMap
{
    unordered_map<string, vector<pair<int, string>>> map;

public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        map[key].push_back({timestamp, value});
    }

    string binarySearch(vector<pair<int, string>> &arr, int timestamp)
    {
        int l = 0;
        int r = arr.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (arr[mid].first <= timestamp)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return r >= 0 ? arr[r].second : "";
    }

    string get(string key, int timestamp)
    {
        return binarySearch(map[key], timestamp);
    }
};