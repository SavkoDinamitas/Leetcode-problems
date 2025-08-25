#include <iostream>
#include <bits-stdc++.h>

using namespace std;

vector<string> result;

void generate(int n, int o, int c, string comb)
{
    if (comb.size() == 2 * n)
    {
        result.push_back(comb);
        return;
    }

    if (o < n)
    {
        generate(n, o + 1, c, comb + '(');
    }
    if (o > c)
    {
        generate(n, o, c + 1, comb + ')');
    }
}

vector<string> generateParenthesis(int n)
{
    generate(n, 0, 0, "");
    return result;
}