#include <iostream>
#include <bits-stdc++.h>
#include <optional>

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

bool isValidBST(TreeNode *root)
{
    stack<TreeNode *> stack;
    TreeNode *curr = root;

    optional<int> prev;
    while (curr || !stack.empty())
    {
        while (curr)
        {
            stack.push(curr);
            curr = curr->left;
        }
        curr = stack.top();
        stack.pop();

        if (prev.has_value() && curr->val <= prev)
            return false;

        prev = curr->val;
        curr = curr->right;
    }
    return true;
}