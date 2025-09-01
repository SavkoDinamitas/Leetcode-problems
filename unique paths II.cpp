#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size()));
    for(int i = 0; i < obstacleGrid.size(); i++){
        for(int j = 0; j < obstacleGrid[0].size(); j++){
            if(i == 0 && j == 0){
                dp[i][j] = (obstacleGrid[i][j] + 1) % 2;
                continue;
            }
            if(obstacleGrid[i][j] == 1){
                dp[i][j] = 0;
                continue;
            }
            int up = i > 0 ? dp[i-1][j] : 0;
            int left = j > 0 ? dp[i][j-1] : 0;
            dp[i][j] = up + left;
        }
    }
    return dp.back().back();
}