#include <iostream>
#include <bits-stdc++.h>

using namespace std;

struct TrieNode
{
    bool isLeaf;
    vector<TrieNode *> children;
    TrieNode() : isLeaf(false), children(26, nullptr) {};
};

class WordDictionary
{
    TrieNode *root;

    bool helpSearch(TrieNode *root, const string &word)
    {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); i++)
        {
            char c = word[i];
            if (c == '.')
            {
                string newWord = word.substr(i + 1);
                bool result = false;
                for (auto next : curr->children)
                {
                    if (next)
                        result = result || helpSearch(next, newWord);
                }
                return result;
            }
            if (!curr->children[c - 'a'])
                return false;
            curr = curr->children[c - 'a'];
        }
        if (curr->isLeaf)
            return true;
        return false;
    }

    bool helpSearchBetter(TrieNode *root, const string &word, int index)
    {
        if (!root)
            return false;

        if (index == word.size())
        {
            return root->isLeaf;
        }

        char c = word[index];

        if (c == '.')
        {
            for (auto next : root->children)
            {
                if (next && helpSearchBetter(next, word, index + 1))
                    return true;
            }
            return false;
        }
        else
        {
            return helpSearchBetter(root->children[word[index] - 'a'], word, index + 1);
        }
    }

public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(string word)
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
        return helpSearchBetter(root, word, 0);
    }
};