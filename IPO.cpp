#include <iostream>
#include <bits-stdc++.h>

using namespace std;

// two heaps
int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeapCapital;
    priority_queue<int> maxHeapProfit;
    for (int i = 0; i < profits.size(); i++)
    {
        minHeapCapital.push({capital[i], profits[i]});
    }

    while (k-- > 0)
    {
        while (!minHeapCapital.empty() && w >= minHeapCapital.top().first)
        {
            auto [c, p] = minHeapCapital.top();
            minHeapCapital.pop();
            maxHeapProfit.push(p);
        }
        if (maxHeapProfit.empty())
            break;
        w += maxHeapProfit.top();
        maxHeapProfit.pop();
    }
    return w;
}

// sort array, both nlogn
int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
{
    vector<pair<int, int>> array;
    for (int i = 0; i < profits.size(); i++)
    {
        array.push_back({capital[i], profits[i]});
    }
    sort(array.begin(), array.end());
    priority_queue<int> pq;
    int index = 0;
    while (k--)
    {
        while (index < profits.size() && w >= array[index].first)
        {
            pq.push(array[index++].second);
        }
        if (pq.empty())
            break;
        w += pq.top();
        pq.pop();
    }
    return w;
}
