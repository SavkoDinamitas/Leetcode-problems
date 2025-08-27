#include <iostream>
#include <bits-stdc++.h>

using namespace std;

class MedianFinder
{
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    int l;
    int r;

public:
    MedianFinder()
    {
        l = 0;
        r = 0;
    }

    void addNum(int num)
    {
        if (left.empty())
        {
            left.push(num);
            l++;
            return;
        }
        if (num < left.top())
        {
            l++;
            left.push(num);
        }
        else
        {
            r++;
            right.push(num);
        }
        // balancing
        if (l > r + 1)
        {
            right.push(left.top());
            left.pop();
            l--;
            r++;
        }
        if (r > l)
        {
            left.push(right.top());
            right.pop();
            l++;
            r--;
        }
    }

    double findMedian()
    {
        if ((l + r) % 2 == 0)
            return (left.top() + right.top()) / 2.0;
        return left.top();
    }
};