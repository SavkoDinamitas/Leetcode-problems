#include <iostream>
#include <bits-stdc++.h>

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    if (nums1.size() > nums2.size())
        return findMedianSortedArrays(nums2, nums1);

    int n1 = nums1.size(), n2 = nums2.size();
    int l = 0, r = n1;
    int half = (n1 + n2) / 2;

    while (l <= r)
    {
        int m1 = l + (r - l) / 2;
        int m2 = half - m1 - 1;

        int left1 = (m1 - 1 >= 0) ? nums1[m1 - 1] : INT_MIN;
        int right1 = (m1 < n1) ? nums1[m1] : INT_MAX;

        int left2 = (m2 >= 0) ? nums2[m2] : INT_MIN;
        int right2 = (m2 + 1 < n2) ? nums2[m2 + 1] : INT_MAX;

        if (left1 <= right2 && left2 <= right1)
        {
            if ((n1 + n2) % 2 == 0)
            {
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            }
            return min(right1, right2);
        }

        if (left1 > right2)
        {
            r = m1 - 1;
        }
        else
        {
            l = m1 + 1;
        }
    }

    return 0;
    return 0;
}