#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int dfs(vector<vector<int>> &grid, int i, int j, int step, int target)
{
    int newStep = step + 1;

    if (grid[i][j] == 2)
    {
        return newStep == target ? 1 : 0;
    }
    if (grid[i][j] == -1)
        return 0;

    grid[i][j] = -1;

    int res = 0;
    // left
    if (j - 1 >= 0)
        res += dfs(grid, i, j - 1, newStep, target);
    // right
    if (j + 1 < grid[0].size())
        res += dfs(grid, i, j + 1, newStep, target);
    // up
    if (i - 1 >= 0)
        res += dfs(grid, i - 1, j, newStep, target);
    // down
    if (i + 1 < grid.size())
        res += dfs(grid, i + 1, j, newStep, target);

    grid[i][j] = 0;
    return res;
}

int uniquePathsIII(vector<vector<int>> &grid)
{
    int si, sj, target = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] != -1)
            {
                target++;
                if (grid[i][j] == 1)
                {
                    si = i;
                    sj = j;
                }
            }
        }
    }
    return dfs(grid, si, sj, 0, target);
}