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

int main()
{
}