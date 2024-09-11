#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*https://leetcode.com/problems/remove-element/?envType=study-plan-v2&envId=top-interview-150*/

int removeElement(vector<int> &nums, int val)
{
    int pointer = 0;
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
        {
            nums[pointer++] = nums[i];
        }
    }
    return pointer;
}

int main()
{
}