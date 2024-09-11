#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150*/

int removeDuplicates(vector<int> &nums)
{
    int pointer = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[pointer - 1])
        {
            nums[pointer++] = nums[i];
        }
    }
    return pointer;
}

/*https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/?envType=study-plan-v2&envId=top-interview-150*/

int removeDuplicatesII(vector<int> &nums)
{
    int pointer = 0;
    int again = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[pointer] && !again)
        {
            again++;
            nums[++pointer] = nums[i];
        }
        if (nums[i] != nums[pointer])
        {
            nums[++pointer] = nums[i];
            again = 0;
        }
    }
    return pointer + 1;
}

int main()
{
}