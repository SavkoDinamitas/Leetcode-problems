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

int calculate(TreeNode *root, int result)
{
    if (!root)
        return 0;
    int curr = result * 10 + root->val;
    if (!root->left && !root->right)
        return curr;
    return calculate(root->left, curr) + calculate(root->right, curr);
}

int sumNumbers(TreeNode *root)
{
    return calculate(root, 0);
}