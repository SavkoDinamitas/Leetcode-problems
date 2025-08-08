#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> result;
    vector<pair<int, int>> steps = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int direction = 0;
    vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
    int i = 0;
    int j = 0;
    int v = 1;
    int m = matrix[0].size();
    int n = matrix.size();
    result.push_back(matrix[0][0]);
    while (v < n * m)
    {
        visited[i][j] = true;
        if (i + steps[direction].first < 0 || i + steps[direction].first >= n ||
            j + steps[direction].second < 0 || j + steps[direction].second >= m || visited[i + steps[direction].first][j + steps[direction].second])
        {
            direction = (direction + 1) % 4;
        }
        else
        {
            v++;
            i += steps[direction].first;
            j += steps[direction].second;
            result.push_back(matrix[i][j]);
        }
    }
    return result;
}
