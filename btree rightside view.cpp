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

vector<int> rightSideView(TreeNode *root)
{
    if (!root)
        return {};

    queue<pair<TreeNode *, int>> queue;
    queue.push(make_pair(root, 1));
    int level = 1;
    vector<int> result = {root->val};
    while (!queue.empty())
    {
        pair<TreeNode *, int> curr = queue.front();
        if (level == curr.second)
        {
            result.back() = curr.first->val;
        }
        else
        {
            result.push_back(curr.first->val);
            level++;
        }
        queue.pop();
        if (curr.first->left)
            queue.push({curr.first->left, curr.second + 1});
        if (curr.first->right)
            queue.push({curr.first->right, curr.second + 1});
    }
    return result;
}