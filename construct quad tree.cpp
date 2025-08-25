#include <iostream>
#include <bits-stdc++.h>

using namespace std;

class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

Node *constructTree(vector<vector<int>> &grid, int ti, int tj, int bi, int bj)
{

    int val = grid[ti][tj];
    bool leaf = true;
    for (int i = ti; i < bi; i++)
    {
        for (int j = tj; j < bj; j++)
        {
            if (grid[i][j] != val)
            {
                leaf = false;
                break;
            }
        }
        if (!leaf)
            break;
    }

    if (leaf)
    {
        return new Node(val, true);
    }

    Node *newNode = new Node(0, false);
    int midRow = (ti + bi) / 2;
    int midCol = (tj + bj) / 2;
    newNode->topLeft = constructTree(grid, ti, tj, midRow, midCol);
    newNode->topRight = constructTree(grid, ti, midCol, midRow, bj);
    newNode->bottomLeft = constructTree(grid, midRow, tj, bi, midCol);
    newNode->bottomRight = constructTree(grid, midRow, midCol, bi, bj);
    return newNode;
}

Node *construct(vector<vector<int>> &grid)
{
    return constructTree(grid, 0, 0, grid.size(), grid.size());
}