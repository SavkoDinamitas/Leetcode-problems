#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*https://leetcode.com/problems/majority-element/?envType=study-plan-v2&envId=top-interview-150*/

int majorityElement(vector<int> &nums)
{
    int cnt = 1;
    int res = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (res != nums[i])
        {
            cnt--;
            if (cnt < 0)
            {
                res = nums[i];
                cnt = 1;
            }
        }
        else
        {
            cnt++;
        }
    }
}

int main()
{
}