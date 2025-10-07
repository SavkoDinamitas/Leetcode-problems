#include <iostream>
#include <bits-stdc++.h>

using namespace std;

class FindSumPairs
{
    vector<int> n1;
    vector<int> n2;
    unordered_map<int, int> map;

public:
    FindSumPairs(vector<int> &nums1, vector<int> &nums2)
    {
        n1 = nums1;
        n2 = nums2;
        for (int i = 0; i < n2.size(); i++)
        {
            map[n2[i]]++;
        }
    }

    void add(int index, int val)
    {
        map[n2[index]]--;
        n2[index] += val;
        map[n2[index]]++;
    }

    int count(int tot)
    {
        int count = 0;
        for (int i = 0; i < n1.size(); i++)
        {
            if (map.count(tot - n1[i]))
            {
                count += map[tot - n1[i]];
            }
        }
        return count;
    }
};