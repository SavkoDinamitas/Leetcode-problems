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

class Solution
{
    int i = 1;
    int kth = INT_MAX;

    void inorder(TreeNode *curr, int k)
    {
        if (!curr)
            return;
        inorder(curr->left, k);
        if (i == k)
        {
            kth = curr->val;
        }
        i++;
        inorder(curr->right, k);
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        inorder(root, k);
        return kth;
    }
};

int kthSmallest(TreeNode *root, int k)
{
    stack<TreeNode *> stack;
    TreeNode *curr = root;
    while (curr || !stack.empty())
    {
        while (curr)
        {
            stack.push(curr);
            curr = curr->left;
        }

        curr = stack.top();
        stack.pop();

        k--;
        if (k == 0)
            return curr->val;

        curr = curr->right;
    }
    return -1;
}