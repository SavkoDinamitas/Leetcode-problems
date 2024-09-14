#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*https://leetcode.com/problems/xor-queries-of-a-subarray/description/*/

vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    vector<int> xors;
    xors.push_back(arr[0]);
    for (int i = 1; i < arr.size(); i++)
    {
        xors.push_back(xors[i - 1] ^ arr[i]);
    }
    vector<int> result;
    for (int i = 0; i < queries.size(); i++)
    {
        if (!queries[i][0])
        {
            result.push_back(xors[queries[i][1]]);
        }
        else
            result.push_back(xors[queries[i][0]] ^ xors[queries[i][1]]);
    }
    return xors;
}

int main()
{
}