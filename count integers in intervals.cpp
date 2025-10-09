#include <iostream>
#include <bits-stdc++.h>

using namespace std;

class CountIntervals
{
    set<pair<int, int>> intervals;
    int result;

public:
    CountIntervals()
    {
        result = 0;
    }

    void add(int left, int right)
    {
        auto it = intervals.lower_bound({left, right});
        if (it != intervals.begin())
        {
            auto prevIt = prev(it);
            if (prevIt->second >= left - 1)
            {
                left = min(left, prevIt->first);
                right = max(right, prevIt->second);
                result -= (prevIt->second - prevIt->first + 1);
                it = intervals.erase(prevIt);
            }
        }
        while (it != intervals.end() && it->first <= right + 1)
        {
            left = min(left, it->first);
            right = max(right, it->second);
            result -= (it->second - it->first + 1);
            it = intervals.erase(it);
        }

        intervals.insert({left, right});
        result += right - left + 1;
    }

    int count()
    {
        return result;
    }
};