#include <iostream>
#include <bits-stdc++.h>

using namespace std;

// O(n*m*logk)
vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
    vector<vector<int>> result;
    priority_queue<pair<int, int>> pq;
    int index = 0;
    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            pq.push({nums1[i] + nums2[j], index++});
            if (index > k)
                pq.pop();
        }
    }
    int m = nums2.size();
    while (!pq.empty())
    {
        auto [sum, index] = pq.top();
        pq.pop();

        result.push_back({nums1[index / m], nums2[index % m]});
    }
    return result;
}

struct Compare
{
    vector<int> *nums1;
    vector<int> *nums2;
    Compare(vector<int> &a, vector<int> &b)
    {
        nums1 = &a;
        nums2 = &b;
    }
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) const
    {
        return (*nums1)[p1.first] + (*nums2)[p1.second] >
               (*nums1)[p2.first] + (*nums2)[p2.second];
    }
};

// O(k*log(k))
vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq((Compare(nums1, nums2)));
    int m = nums2.size();
    vector<vector<int>> result;
    pq.push({0, 0});
    unordered_set<int> visited;
    while (!pq.empty() && result.size() < k)
    {
        auto [i, j] = pq.top();
        pq.pop();
        result.push_back({nums1[i], nums2[j]});
        if (i < nums1.size() - 1 && !visited.count((i + 1) * m + j))
        {
            pq.push({i + 1, j});
            visited.insert((i + 1) * m + j);
        }
        if (j < nums2.size() && !visited.count(i * m + j + 1))
        {
            pq.push({i, j + 1});
            visited.insert(i * m + j + 1);
        }
    }
    return result;
}

vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                   int k)
{
    vector<vector<int>> result;
    if (nums1.empty() || nums2.empty() || k == 0)
        return result;

    // Min-heap: (sum, i, j)
    auto cmp = [&](const tuple<int, int, int> &a,
                   const tuple<int, int, int> &b)
    {
        return get<0>(a) > get<0>(b); // min-heap on sum
    };
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   decltype(cmp)>
        pq(cmp);

    // Push first column of pairs (nums1[i], nums2[0])
    for (int i = 0; i < nums1.size() && i < k; i++)
    {
        pq.push({nums1[i] + nums2[0], i, 0});
    }

    // Extract k smallest sums
    while (k-- > 0 && !pq.empty())
    {
        auto [sum, i, j] = pq.top();
        pq.pop();
        result.push_back({nums1[i], nums2[j]});

        // Move right in nums2
        if (j + 1 < nums2.size())
        {
            pq.push({nums1[i] + nums2[j + 1], i, j + 1});
        }
    }

    return result;
}