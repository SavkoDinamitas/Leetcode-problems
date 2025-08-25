#include <iostream>
#include <bits-stdc++.h>

using namespace std;

bool find(vector<vector<char>> &board, const string &word, int idx, int i, int j)
{
    if (word.size() == idx)
        return true;
    if (board[i][j] == '#' || board[i][j] != word[idx] || i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
    {
        return false;
    }
    char c = board[i][j];
    board[i][j] = '#';

    bool found = find(board, word, idx + 1, i - 1, j) ||
                 find(board, word, idx + 1, i + 1, j) ||
                 find(board, word, idx + 1, i, j - 1) ||
                 find(board, word, idx + 1, i, j + 1);

    board[i][j] = c;
    return found;
}

bool exist(vector<vector<char>> &board, string word)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (find(board, word, 0, i, j))
                return true;
        }
    }
    return false;
}