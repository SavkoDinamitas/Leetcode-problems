#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
    unordered_set<int> numbers;
    // check every row
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.' && !numbers.insert(board[i][j]).second)
                return false;
        }
        numbers.clear();
    }
    // check every column
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[j][i] != '.' && !numbers.insert(board[j][i]).second)
                return false;
        }
        numbers.clear();
    }
    // check every 3x3 square
    for (int i = 0; i < 9; i++)
    {
        int rl = (i / 3) * 3;
        int rr = rl + 3;
        while (rl < rr)
        {
            int cl = (i % 3) * 3;
            int cr = cl + 3;
            while (cl < cr)
            {
                if (board[rl][cl] != '.' && !numbers.insert(board[rl][cl]).second)
                    return false;
                cl++;
            }
            rl++;
        }
        numbers.clear();
    }
    return true;
}

int main()
{
}