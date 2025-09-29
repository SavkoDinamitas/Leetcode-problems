#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if(nums[i] <= 0) nums[i] = n + 1;
    }

    for(int i = 0; i < n; i++){
        int next = nums[i];
        while(next > 0 && next <= n){
            int p = next - 1;
            next = nums[p];
            nums[p] = -1;
        }
    }

    for(int i = 0; i < n; i++){
        if(nums[i] >= 0)
            return i+1;
    }
    return n + 1;
}