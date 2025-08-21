#include <iostream>
#include <bits-stdc++.h>

using namespace std;

void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int i, int j)
{
    if (i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0 || grid[i][j] == '0' || visited[i][j])
        return;

    visited[i][j] = true;
    dfs(grid, visited, i - 1, j);
    dfs(grid, visited, i + 1, j);
    dfs(grid, visited, i, j + 1);
    dfs(grid, visited, i, j - 1);
}

int numIslands(vector<vector<char>> &grid)
{
    if (grid.empty())
        return 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1' && !visited[i][j])
            {
                res++;
                dfs(grid, visited, i, j);
            }
        }
    }
    return res;
}