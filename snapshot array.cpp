#include <iostream>
#include <bits-stdc++.h>

using namespace std;

class SnapshotArray
{
    vector<vector<pair<int, int>>> arr;
    int snapshot;

public:
    SnapshotArray(int length)
    {
        snapshot = 0;
        for (int i = 0; i < length; i++)
        {
            arr.push_back({{snapshot, 0}});
        }
    }

    void set(int index, int val)
    {
        arr[index].push_back({snapshot, val});
    }

    int snap()
    {
        return snapshot++;
    }

    int binarySearch(vector<pair<int, int>> &arr, int snapshot)
    {
        int l = 0;
        int r = arr.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (arr[mid].first <= snapshot)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return arr[r].second;
    }

    int get(int index, int snap_id)
    {
        return binarySearch(arr[index], snap_id);
    }
};
