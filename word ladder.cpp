#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_map<string, bool> valid;
    for (string s : wordList)
    {
        valid[s] = false;
    }

    queue<pair<string, int>> q;
    q.push({beginWord, 1});

    while (!q.empty())
    {
        auto [curr, step] = q.front();
        q.pop();

        if (curr == endWord)
            return step;
        string newWord = curr;
        for (int i = 0; i < curr.size(); i++)
        {
            for (char l = 'a'; l <= 'z'; l++)
            {
                if (curr[i] == l)
                    continue;
                newWord[i] = l;
                if (valid.find(newWord) != valid.end() && !valid[newWord])
                {
                    q.push({newWord, step + 1});
                    valid[newWord] = true;
                }
            }
            newWord[i] = curr[i];
        }
    }

    return 0;
}

// bidirectional bfs
int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> dictionary(wordList.begin(), wordList.end());

    if (!dictionary.count(endWord))
        return 0;

    unordered_set<string> beginSet({beginWord});
    unordered_set<string> endSet({endWord});
    unordered_set<string> visited;

    int step = 1;

    while (!beginSet.empty() && !endSet.empty())
    {
        if (beginSet.size() > endSet.size())
            swap(beginSet, endSet);

        unordered_set<string> next;
        for (const string &word : beginSet)
        {
            string newWord = word;
            for (int i = 0; i < newWord.size(); i++)
            {
                for (char j = 'a'; j <= 'z'; j++)
                {
                    if (j == word[i])
                        continue;
                    newWord[i] = j;
                    if (endSet.count(newWord))
                        return step + 1;
                    if (dictionary.count(newWord) && !visited.count(newWord))
                    {
                        next.insert(newWord);
                        visited.insert(newWord);
                    }
                }
            }
            beginSet = next;
            step++;
        }
    }
}