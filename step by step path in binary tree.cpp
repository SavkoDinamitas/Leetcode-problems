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
    vector<char> first;
    vector<char> second;

public:
    void findPaths(TreeNode *root, int a, int b, vector<char> &path)
    {
        if (!root)
        {
            return;
        }
        if (root->val == a)
            first = path;

        if (root->val == b)
            second = path;
        path.push_back('L');
        findPaths(root->left, a, b, path);
        path.pop_back();
        path.push_back('R');
        findPaths(root->right, a, b, path);
        path.pop_back();
    }
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        vector<char> p;
        findPaths(root, startValue, destValue, p);
        int same = 0;
        while (same < first.size() && same < second.size() && first[same] == second[same])
        {
            same++;
        }
        string path = "";
        for (int i = 0; i < first.size() - same; i++)
        {
            path += "U";
        }
        for (int i = same; i < second.size(); i++)
        {
            path += second[i];
        }
        return path;
    }
};