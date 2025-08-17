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

class BSTIterator
{
private:
    stack<TreeNode *> stack;

public:
    BSTIterator(TreeNode *root)
    {
        while (root)
        {
            stack.push(root);
            root = root->left;
        }
    }

    int next()
    {
        TreeNode *node = stack.top();
        stack.pop();
        if (node->right)
        {
            TreeNode *xd = node->right;
            while (xd)
            {
                stack.push(xd);
                xd = xd->left;
            }
        }
        return node->val;
    }

    bool hasNext()
    {
        return !stack.empty();
    }
};

class BSTIterator
{
private:
    TreeNode *curr;

public:
    BSTIterator(TreeNode *root)
    {
        curr = root;
    }

    int next()
    {
        int res = -1;
        while (curr)
        {
            if (!curr->left)
            {
                res = curr->val;
                curr = curr->right;
                break;
            }
            else
            {
                TreeNode *pred = curr->left;
                while (pred->right && pred->right != curr)
                {
                    pred = pred->right;
                }

                if (!pred->right)
                {
                    pred->right = curr;
                    curr = curr->left;
                }
                else
                {
                    pred->right = nullptr;
                    res = curr->val;
                    curr = curr->right;
                    break;
                }
            }
        }
        return res;
    }

    bool hasNext()
    {
        return curr != nullptr;
    }
};