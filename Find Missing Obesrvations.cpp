#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/find-missing-observations/?envType=daily-question&envId=2024-09-05
*/

vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int difference = 0;
        for(int i = 0; i < rolls.size(); i++){
            difference += mean - rolls[i];
        }
        vector<int> result;
        if(difference > 0 && (difference > (6 - mean) * n)){
            return result;
        }
        if(difference < 0 && (abs(difference) > (mean - 1) * n)){
            return result;
        }
        //fill the array with mean values
        for(int i = 0; i < n; i++){
            result.push_back(mean);
        }

        //resolving the difference needed
        int pos = 0;
        while(difference != 0){
            if(difference > 0){
                if(difference < (6 - mean)){
                    result[pos] += difference;
                    difference = 0;
                }
                else{
                    result[pos] = 6;
                    difference -= (6 - mean);
                }
            }
            else{
                if(difference > (1 - mean)){
                    result[pos] += difference;
                    difference = 0;
                }
                else{
                    result[pos] = 1;
                    difference += (mean - 1);
                }
            }
            pos++;
        }
        return result;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
