#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int shortestPath(vector<vector<int>> &grid, int k)
{
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    int steps = 0;
    vector<vector<int>> obstacles(grid.size(), vector<int>(grid[0].size(), INT_MAX));
    while (!q.empty())
    {
        int n = q.size();

        for (int x = 0; x < n; x++)
        {
            auto [i, j, obs] = q.front();
            q.pop();
            obstacles[i][j] = min(obstacles[i][j], obs);

            if (i == grid.size() - 1 && j == grid[0].size() - 1)
            {
                return steps;
            }

            // left
            if (j - 1 >= 0)
            {
                if (grid[i][j - 1] == 1 && obs < k && obstacles[i][j - 1] > obs + 1)
                {
                    q.push({i, j - 1, obs + 1});
                    obstacles[i][j - 1] = obs + 1;
                }
                else if (!grid[i][j - 1])
                {
                    if (obstacles[i][j - 1] > obs)
                    {
                        q.push({i, j - 1, obs});
                        obstacles[i][j - 1] = obs;
                    }
                }
            }
            // right
            if (j + 1 < grid[0].size())
            {
                if (grid[i][j + 1] == 1 && obs < k && obstacles[i][j + 1] > obs + 1)
                {
                    q.push({i, j + 1, obs + 1});
                    obstacles[i][j + 1] = obs + 1;
                }
                else if (!grid[i][j + 1])
                {
                    if (obstacles[i][j + 1] > obs)
                    {
                        q.push({i, j + 1, obs});
                        obstacles[i][j + 1] = obs;
                    }
                }
            }
            // top
            if (i - 1 >= 0)
            {
                if (grid[i - 1][j] == 1 && obs < k && obstacles[i - 1][j] > obs + 1)
                {
                    q.push({i - 1, j, obs + 1});
                    obstacles[i - 1][j] = obs + 1;
                }
                else if (!grid[i - 1][j])
                {
                    if (obstacles[i - 1][j] > obs)
                    {
                        q.push({i - 1, j, obs});
                        obstacles[i - 1][j] = obs;
                    }
                }
            }
            // bottom
            if (i + 1 < grid.size())
            {
                if (grid[i + 1][j] == 1 && obs < k && obstacles[i + 1][j] > obs + 1)
                {
                    q.push({i + 1, j, obs + 1});
                    obstacles[i + 1][j] = obs + 1;
                }
                else if (!grid[i + 1][j])
                {
                    if (obstacles[i + 1][j] > obs)
                    {
                        q.push({i + 1, j, obs});
                        obstacles[i + 1][j] = obs;
                    }
                }
            }
        }
        steps++;
    }
    return -1;
}