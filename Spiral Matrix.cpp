#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*https://leetcode.com/problems/spiral-matrix-iv/description/*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
{
    int directionX[4] = {1, 0, -1, 0};
    int directionY[4] = {0, 1, 0, -1};
    int dir = 0;

    vector<vector<int>> matrix(m, vector<int>(n, -1));
    int x = 0;
    int y = 0;
    int d = 0;
    int r = 0;
    while (head->next != nullptr)
    {
        matrix[y][x] = head->val;
        head = head->next;
        x += directionX[dir];
        y += directionY[dir];
        if (x < r || x >= n || y < d || y >= m || matrix[y][x] != -1)
        {
            x -= directionX[dir];
            y -= directionY[dir];
            dir = (dir + 1) % 4;
            x += directionX[dir];
            y += directionY[dir];
        }
    }
    matrix[y][x] = head->val;
    return matrix;
}

int main()
{
}