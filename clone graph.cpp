#include <iostream>
#include <bits-stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

Node *dfs(Node *node, unordered_map<Node *, Node *> &map)
{
    Node *newNode = new Node(node->val);
    map[node] = newNode;
    for (int i = 0; i < node->neighbors.size(); i++)
    {
        if (map[node->neighbors[i]] == nullptr)
        {
            newNode->neighbors.push_back(dfs(node->neighbors[i], map));
        }
        else
        {
            newNode->neighbors.push_back(map[node->neighbors[i]]);
        }
    }
    return newNode;
}

Node *cloneGraph(Node *node)
{
    if (!node)
        return nullptr;
    unordered_map<Node *, Node *> map;
    return dfs(node, map);
}