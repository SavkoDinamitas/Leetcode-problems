#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    pair<int, int> tl, tr, br, bl;
    tl = make_pair(0, 0);
    tr = make_pair(0, n - 1);
    br = make_pair(n - 1, n - 1);
    bl = make_pair(n - 1, 0);
    int k = 0;
    while (tl.second < tr.second)
    {
        for (int i = 0; i < n - 1 - 2 * k; i++)
        {
            int h = matrix[tl.first][tl.second];
            matrix[tl.first][tl.second] = matrix[bl.first][bl.second];
            matrix[bl.first][bl.second] = matrix[br.first][br.second];
            matrix[br.first][br.second] = matrix[tr.first][tr.second];
            matrix[tr.first][tr.second] = h;
            tl.second++;
            tr.first++;
            br.second--;
            bl.first--;
        }
        k++;
        tl = make_pair(k, k);
        tr = make_pair(k, n - 1 - k);
        br = make_pair(n - k - 1, n - k - 1);
        bl = make_pair(n - 1 - k, k);
    }
}