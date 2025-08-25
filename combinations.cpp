#include <iostream>
#include <bits-stdc++.h>

using namespace std;

vector<vector<int>> result;

void combinations(int n, int k, vector<int> &comb)
{
    if (comb.size() == k)
    {
        result.push_back(comb);
        return;
    }
    int i = comb.size() != 0 ? comb.back() + 1 : 1;
    while (i <= n)
    {
        comb.push_back(i);
        combinations(n, k, comb);
        comb.pop_back();
        i++;
    }
}

vector<vector<int>> combine(int n, int k)
{
    if (k == 0)
        return {{}};
    vector<int> comb;
    combinations(n, k, comb);
    return result;
}