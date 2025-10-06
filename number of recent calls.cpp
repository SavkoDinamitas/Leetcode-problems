#include <iostream>
#include <bits-stdc++.h>

using namespace std;

class RecentCounter
{
    queue<int> pings;

public:
    RecentCounter()
    {
    }

    int ping(int t)
    {
        pings.push(t);
        while (pings.front() < t - 3000)
        {
            pings.pop();
        }
        return pings.size();
    }
};