#include <iostream>
#include <bits-stdc++.h>

using namespace std;

vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    vector<string> result;
    int i = 0;
    while (i < words.size())
    {
        int size = 0, w = 0;
        string line = "";
        while (i < words.size() && size + words[i].length() + (size != 0) <= maxWidth)
        {
            size +=
                size != 0 ? words[i++].length() + 1 : words[i++].length();
            w++;
        }
        int spaces = maxWidth - size;
        int base = spaces / max(w - 1, 1);
        int leftover = spaces % max(w - 1, 1);
        if (i < words.size())
            for (int j = i - w; j < i; j++)
            {
                line += words[j];
                if (j != i - 1 || w == 1)
                {
                    int x = w != 1 ? base + 1 + (leftover-- > 0) : spaces;
                    for (int s = 0; s < x; s++)
                    {
                        line += " ";
                    }
                }
            }
        else
        {
            int xd = 0;
            for (int j = i - w; j < i; j++)
            {
                line += words[j];
                if (j != i - 1)
                    line += " ";
            }
            while (size++ < maxWidth)
            {
                line += " ";
            }
        }
        result.push_back(line);
    }
    return result;
}