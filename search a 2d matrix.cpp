#include <iostream>
#include <bits-stdc++.h>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int l = 0;
    int r = n * m - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        int el = matrix[mid / m][mid % m];

        if (el == target)
            return true;
        if (el < target)
        {
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return false;
}