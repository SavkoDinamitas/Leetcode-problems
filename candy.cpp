#include <iostream>
#include <bits-stdc++.h>

using namespace std;

// O(n^2) time
int candy(vector<int> &ratings)
{
    int n = ratings.size();
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int l = i - 1, r = i + 1;
        int left = 0;
        int right = 0;
        while (l > 0 && ratings[l] < ratings[l + 1])
        {
            left++;
            l--;
        }
        while (r < n && ratings[r] < ratings[r - 1])
        {
            right++;
            r++;
        }
        result += max(left, right) + 1;
    }
    return result;
}
// O(n) time
int candy(vector<int> &ratings)
{
    int n = ratings.size();
    vector<int> res(n);
    res[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            res[i] = res[i - 1] + 1;
        }
        else
            res[i] = 1;
    }
    res[n - 1] = max(res[n - 1], 1);
    int curr = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
        {
            res[i] = max(res[i], ++curr);
        }
        else
            curr = 1;
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result += res[i];
    }
    return result;
}
