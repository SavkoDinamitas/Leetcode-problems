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

TreeNode *generateTree(vector<int> &nums, int l, int r)
{
    if (l > r)
        return nullptr;
    int m = (l + r) / 2;
    TreeNode *node = new TreeNode(nums[m]);
    node->left = generateTree(nums, l, m - 1);
    node->right = generateTree(nums, m + 1, r);
    return node;
}

TreeNode *sortedArrayToBST(vector<int> &nums)
{
    return generateTree(nums, 0, nums.size() - 1);
}