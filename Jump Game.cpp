#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*https://leetcode.com/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150*/

bool canJump(vector<int> &nums)
{
    int maxJmp = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        maxJmp = max(maxJmp, nums[i]);
        if (!maxJmp && i != nums.size() - 1)
            return false;
        maxJmp--;
    }
    return true;
}

int minJumps(vector<int> nums)
{
    int n = nums.size();
    int currJmp = 0;
    int maxJmp = 0;
    int jmp = 0;
    for (int i = 0; i < n; i++)
    {
        if (i > maxJmp)
        {
            jmp++;
            maxJmp = currJmp;
        }
        if (i + nums[i] > currJmp)
        {
            currJmp = i + nums[i];
        }
    }
    return jmp;
}

int main()
{
}