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
    int maximum = INT_MIN;

public:
    int calculate(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        // from here down including me
        int left = calculate(root->left);
        int right = calculate(root->right);

        // only me
        int currMax = root->val;
        // me with better branch
        currMax = max(currMax, max(left, right) + root->val);
        // with me and both branches, then can't connect
        maximum = max(maximum, left + right + root->val);
        // update global
        maximum = max(maximum, currMax);

        return currMax;
    }

    int maxPathSum(TreeNode *root)
    {
        calculate(root);
        return maximum;
    }
};