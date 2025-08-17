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

TreeNode *build(unordered_map<int, int> &inorderIndex, vector<int> &preorder, vector<int> &inorder, int pstart, int istart, int iend)
{
    if (istart > iend)
    {
        return nullptr;
    }
    TreeNode *root = new TreeNode(preorder[pstart]);
    int ilocation = inorderIndex[preorder[pstart]];
    int leftsize = ilocation - istart;
    root->left = build(inorderIndex, preorder, inorder, pstart + 1, istart, ilocation - 1);
    root->right = build(inorderIndex, preorder, inorder, pstart + leftsize + 1, ilocation + 1, iend);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    unordered_map<int, int> inorderIndex;
    for (int i = 0; i < inorder.size(); i++)
    {
        inorderIndex[inorder[i]] = i;
    }
    return build(inorderIndex, preorder, inorder, 0, 0, preorder.size() - 1);
}