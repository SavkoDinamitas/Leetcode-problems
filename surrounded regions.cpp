#include <iostream>
#include <bits-stdc++.h>

using namespace std;

void dfs(vector<vector<char>> &board, int i, int j)
{
    if (board[i][j] == 'X')
        return;
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    board[i][j] = '#';
    for (auto [dx, dy] : directions)
    {
        int ni = i + dy;
        int nj = j + dx;
        if (ni >= 0 && ni < board.size() && nj >= 0 && nj < board[0].size() && board[ni][nj] == 'O')
            dfs(board, ni, nj);
    }
}

void solve(vector<vector<char>> &board)
{
    if (board.empty())
        return;
    for (int i = 0; i < board.size(); i++)
    {
        dfs(board, i, 0);
        dfs(board, i, board[0].size() - 1);
    }
    for (int j = 0; j < board[0].size(); j++)
    {
        dfs(board, 0, j);
        dfs(board, board.size() - 1, j);
    }

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == 'O')
                board[i][j] = 'X';
            else if (board[i][j] == '#')
                board[i][j] = 'O';
        }
    }
}