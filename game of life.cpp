#include <iostream>
#include <bits-stdc++.h>

using namespace std;

vector<pair<int, int>> neighbors = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

int liveNeighbors(int i, int j, vector<vector<int>> &board)
{
    int n = board.size();
    int m = board[0].size();
    int c = 0;
    for (int l = 0; l < 8; l++)
    {
        if (i + neighbors[l].first < 0 || i + neighbors[l].first >= n || j + neighbors[l].second < 0 || j + neighbors[l].second >= m)
            continue;
        if (board[i + neighbors[l].first][j + neighbors[l].second] == 1)
            c++;
    }
    return c;
}

void gameOfLife(vector<vector<int>> &board)
{
    int n = board.size();
    int m = board[0].size();
    vector<pair<int, int>> changes;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int live = liveNeighbors(i, j, board);
            if (board[i][j] == 1 && live < 2)
                changes.push_back(make_pair(i, j));
            else if (board[i][j] == 1 && live > 3)
                changes.push_back(make_pair(i, j));
            else if (board[i][j] == 0 && live == 3)
                changes.push_back(make_pair(i, j));
        }
    }

    for (int i = 0; i < changes.size(); i++)
    {
        board[changes[i].first][changes[i].second] = (board[changes[i].first][changes[i].second] + 1) % 2;
    }
}