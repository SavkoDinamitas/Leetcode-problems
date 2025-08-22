#include <iostream>
#include <bits-stdc++.h>

using namespace std;

struct TrieNode
{
    bool isLeaf;
    vector<TrieNode *> children;
    TrieNode() : isLeaf(false), children(26, nullptr) {};
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *curr = root;
        for (char c : word)
        {
            if (!curr->children[c - 'a'])
            {
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isLeaf = true;
    }

    bool search(string word)
    {
        TrieNode *curr = root;
        for (char c : word)
        {
            if (!curr->children[c - 'a'])
                return false;
            curr = curr->children[c - 'a'];
        }
        if (curr->isLeaf)
            return true;
        return false;
    }

    bool startsWith(string prefix)
    {
        TrieNode *curr = root;
        for (char c : prefix)
        {
            if (!curr->children[c - 'a'])
                return false;
            curr = curr->children[c - 'a'];
        }
        return true;
    }
};
