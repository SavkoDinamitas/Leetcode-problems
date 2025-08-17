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

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == nullptr && q == nullptr)
        return true;
    if (p == nullptr || q == nullptr)
        return false;
    return isSameTree(p->left, q->left) && p->val == q->val && isSameTree(p->right, q->right);
}

bool isMirrored(TreeNode *p, TreeNode *q)
{
    if (p == nullptr && q == nullptr)
        return true;
    if (p == nullptr || q == nullptr)
        return false;
    return isSameTree(p->left, q->right) && p->val == q->val && isSameTree(p->right, q->left);
}

bool isSymmetric(TreeNode *root)
{
    if (!root)
        return true;
    return isMirrored(root->left, root->right);
}