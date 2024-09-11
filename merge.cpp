#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*https://leetcode.com/problems/merge-sorted-array/?envType=study-plan-v2&envId=top-interview-150*/

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int l = 0;
    int r = 0;
    vector<int> c;
    for (int i = 0; i < m; i++)
    {
        c.push_back(nums1[i]);
    }

    int i = 0;
    while (l < m && r < n)
    {
        if (c[l] < nums2[r])
        {
            nums1[i++] = c[l++];
        }
        else
        {
            nums1[i++] = nums2[r++];
        }
    }

    while (l < m)
    {
        nums1[i++] = c[l++];
    }

    while (r < n)
    {
        nums1[i++] = nums2[r++];
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
