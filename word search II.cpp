#include <iostream>
#include <bits-stdc++.h>

using namespace std;

struct TrieNode
{
    string isLeaf;
    vector<TrieNode *> children;
    TrieNode() : isLeaf(""), children(26, nullptr) {};
};

TrieNode *generateTrie(vector<string> &words)
{
    TrieNode *root = new TrieNode();

    for (string word : words)
    {
        TrieNode *curr = root;
        for (char c : word)
        {
            if (!curr->children[c - 'a'])
                curr->children[c - 'a'] = new TrieNode();
            curr = curr->children[c - 'a'];
        }
        curr->isLeaf = word;
    }
    return root;
}

void dfs(vector<vector<char>> &board, TrieNode *node, int i, int j, vector<string> &result)
{
    char c = board[i][j];

    if (c == '#' || !node->children[c - 'a'])
        return;

    TrieNode *next = node->children[c - 'a'];

    if (next->isLeaf != "")
    {
        result.push_back(next->isLeaf);
        next->isLeaf = "";
    }

    board[i][j] = '#';

    if (i > 0)
        dfs(board, next, i - 1, j, result);
    if (i + 1 < (int)board.size())
        dfs(board, next, i + 1, j, result);
    if (j > 0)
        dfs(board, next, i, j - 1, result);
    if (j + 1 < (int)board[0].size())
        dfs(board, next, i, j + 1, result);
    board[i][j] = c;

    // pruning step
    bool hasChildren = false;
    for (TrieNode *child : next->children)
    {
        if (child)
        {
            hasChildren = true;
            break;
        }
    }
    if (!hasChildren && next->isLeaf.empty())
    {
        delete next;
        node->children[c - 'a'] = nullptr;
    }
}

vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
{
    TrieNode *root = generateTrie(words);
    vector<string> result;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            dfs(board, root, i, j, result);
        }
    }
    return result;
}