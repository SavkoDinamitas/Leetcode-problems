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

TreeNode *build(unordered_map<int, int> &inorderIndex, vector<int> &postorder, vector<int> &inorder, int pstart, int istart, int iend)
{
    if (istart > iend)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode(postorder[pstart]);
    int ilocation = inorderIndex[postorder[pstart]];
    int rightsize = iend - ilocation;

    root->right = build(inorderIndex, postorder, inorder, pstart - 1,
                        ilocation + 1, iend);
    root->left = build(inorderIndex, postorder, inorder,
                       pstart - rightsize - 1, istart, ilocation - 1);

    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    unordered_map<int, int> inorderIndex;
    for (int i = 0; i < inorder.size(); i++)
    {
        inorderIndex[inorder[i]] = i;
    }
    return build(inorderIndex, postorder, inorder, postorder.size() - 1, 0, postorder.size() - 1);
}