#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int minMutation(string startGene, string endGene, vector<string> &bank)
{
    char genes[] = {'A', 'C', 'G', 'T'};
    unordered_map<string, bool> valid;
    for (string s : bank)
    {
        valid[s] = false;
    }

    queue<pair<string, int>> q;
    q.push({startGene, 0});

    while (!q.empty())
    {
        auto [curr, step] = q.front();
        q.pop();

        if (curr == endGene)
            return step;
        string newGene = curr;
        for (int i = 0; i < curr.size(); i++)
        {
            for (char l : genes)
            {
                if (curr[i] == l)
                    continue;
                newGene[i] = l;
                if (valid.find(newGene) != valid.end() && !valid[newGene])
                {
                    q.push({newGene, step + 1});
                    valid[newGene] = true;
                }
            }
            newGene[i] = curr[i];
        }
    }

    return -1;
}