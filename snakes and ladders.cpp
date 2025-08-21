#include <iostream>
#include <bits-stdc++.h>

using namespace std;

pair<int, int> transform(int curr, int n)
{
    int i = (curr - 1) / n;
    int j = (curr - 1) % n;
    if (i % 2 != 0)
        j = n - j - 1;
    return {n - i - 1, j};
}

int snakesAndLadders(vector<vector<int>> &board)
{
    int n = board.size();
    queue<pair<int, int>> q;
    q.push({1, 0});
    vector<bool> visited(n * n + 1);
    visited[1] = true;
    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();
        if (curr.first == n * n)
            return curr.second;
        for (int i = curr.first + 1; i <= min(curr.first + 6, n * n); i++)
        {
            auto [x, y] = transform(i, n);
            int next = (board[x][y] == -1) ? i : board[x][y];
            if (next == n * n)
                return curr.second + 1;
            if (!visited[next])
            {
                visited[next] = true;
                q.push({next, curr.second + 1});
            }
        }
    }
    return -1;
}