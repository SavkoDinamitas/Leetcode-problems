#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int hIndex(vector<int> &citations)
{
    sort(citations.begin(), citations.end());
    int n = citations.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (citations[i] <= n - i)
            return max(citations[i], n - i - 1);
    }
    return n;
}

int main()
{
}