#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> set(nums.begin(), nums.end());
    int result = 0;
    for (int num : set)
    {
        if (set.count(num - 1) > 0)
            continue;
        int cnt = 1;
        while (set.count(num + cnt) > 0)
        {
            cnt++;
        }
        result = max(result, cnt);
    }
    return result;
}

// legendary solution
int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> set(nums.begin(), nums.end());
    unordered_map<int, int> map;
    int result;
    for (int num : set)
    {
        int l = map[num - 1];
        int r = map[num + 1];
        int curr = l + r + 1;
        map[num - l] = curr;
        map[num + r] = curr;
        result = max(result, curr);
    }
    return result;
}