#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int findSmallestInteger(vector<int> &nums, int value)
{
    vector<int> found(nums.size(), -1);
    for (int i = 0; i < nums.size(); i++)
    {
        int m = nums[i] % value;
        m = m < 0 ? value + m : m;
        if (m >= found.size())
            continue;
        if (found[m] == -1)
        {
            found[m] = m + value;
        }
        else if (found[m] < found.size())
        {
            found[found[m]] = found[m] + value;
            found[m] += value;
        }
    }
    for (int i = 0; i < found.size(); i++)
    {
        if (found[i] == -1)
            return i;
    }
    return found.size();
}

int main()
{
    cout << endl
         << (-13 % 4);
}