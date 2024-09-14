#include <iostream>
#include <bits/stdc++.h>

/*https://leetcode.com/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150*/

using namespace std;

void rotate(vector<int> &nums, int k)
{
    k %= nums.size();
    int l = 0;
    int r = nums.size() - 1;
    while (l < r)
    {
        int pom = nums[l];
        nums[l] = nums[r];
        nums[r] = pom;
        l++;
        r--;
    }

    l = 0;
    r = k - 1;
    while (l < r)
    {
        int pom = nums[l];
        nums[l] = nums[r];
        nums[r] = pom;
        l++;
        r--;
    }

    l = k;
    r = nums.size() - 1;
    while (l < r)
    {
        int pom = nums[l];
        nums[l] = nums[r];
        nums[r] = pom;
        l++;
        r--;
    }
}

int main()
{
}