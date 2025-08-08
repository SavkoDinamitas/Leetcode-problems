#include <iostream>
#include <bits-stdc++.h>

using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    bool found = false;
    int n = matrix.size();
    int m = matrix[0].size();
    // checking rows
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] != 0)
                    matrix[i][j] = INT_MIN;
            }
        }
        found = false;
    }
    // checking columns
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[j][i] == 0)
            {
                found = true;
                break;
            }
        }
        if (found)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[j][i] != 0)
                    matrix[j][i] = INT_MIN;
            }
        }
        found = false;
    }
    // place all zeros
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == INT_MIN)
                matrix[i][j] = 0;
        }
    }
}