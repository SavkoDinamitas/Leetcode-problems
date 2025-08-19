#include <iostream>
#include <bits-stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// hacky solution
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    if (!root)
        return {};

    queue<pair<TreeNode *, int>> queue;
    queue.push(make_pair(root, 1));
    int level = 0;
    vector<vector<int>> result;
    while (!queue.empty())
    {
        pair<TreeNode *, int> curr = queue.front();
        if (level == curr.second)
        {
            result.back().push_back(curr.first->val);
        }
        else
        {
            result.push_back({curr.first->val});
            level++;
        }
        queue.pop();
        if (curr.first->left)
            queue.push({curr.first->left, curr.second + 1});
        if (curr.first->right)
            queue.push({curr.first->right, curr.second + 1});
    }
    for (int i = 1; i < result.size(); i += 2)
    {
        int l = 0;
        int r = result[i].size() - 1;
        while (l < r)
        {
            int s = result[i][l];
            result[i][l] = result[i][r];
            result[i][r] = s;
            l++;
            r--;
        }
    }
    return result;
}

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> result;
    if (!root)
        return result;

    queue<TreeNode *> queue;
    queue.push(root);
    bool lr = true;
    while (!queue.empty())
    {
        int size = queue.size();
        vector<int> level(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *curr = queue.front();
            queue.pop();

            int idx = lr ? i : size - 1 - i;
            level[idx] = curr->val;

            if (curr->left)
                queue.push(curr->left);
            if (curr->right)
                queue.push(curr->right);
        }
        result.push_back(level);
        lr = !lr;
    }
    return result;
}