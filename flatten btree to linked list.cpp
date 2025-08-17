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

TreeNode *makeTree(TreeNode *root)
{
    if (!root)
        return nullptr;
    TreeNode *result = new TreeNode(root->val);
    TreeNode *left = makeTree(root->left);
    TreeNode *right = makeTree(root->right);
    if (left)
    {
        result->right = left;
    }
    if (right)
    {
        TreeNode *lol = result;
        while (lol->right)
        {
            lol = lol->right;
        }
        lol->right = right;
    }
    return result;
}

void flatten(TreeNode *root)
{
    TreeNode *xd = makeTree(root);
    if (!xd || !xd->right)
        return;
    xd = xd->right;
    while (xd)
    {
        root->left = nullptr;
        root->right = xd;
        root = root->right;
        xd = xd->right;
    }
}

// better solution
void flatten(TreeNode *root)
{
    if (!root)
        return;

    flatten(root->left);
    flatten(root->right);

    TreeNode *tmpRight = root->right;
    root->right = root->left;
    root->left = nullptr;

    TreeNode *curr = root;
    while (curr->right)
        curr = curr->right;
    curr->right = tmpRight;
}

// best solution
void flatten(TreeNode *root)
{
    if (!root)
        return;

    TreeNode *curr = root;
    while (curr)
    {
        if (curr->left)
        {
            TreeNode *rightMost = curr->left;
            while (rightMost->right)
                rightMost = rightMost->right;

            rightMost->right = curr->right;
            curr->right = curr->left;
            curr->left = nullptr;
        }
        curr = curr->right;
    }
}