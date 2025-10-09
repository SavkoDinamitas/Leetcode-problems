#include <iostream>
#include <bits-stdc++.h>

using namespace std;

// solution for longest common prefix of all pairs
int calcPrefix(int a, int b)
{
    while (a != b)
    {
        if (a < b)
            b /= 10;
        else
            a /= 10;
    }
    return a;
}

int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
{
    int prefix = arr1[0];
    for (int i = 1; i < arr1.size(); i++)
    {
        prefix = calcPrefix(prefix, arr1[i]);
    }
    for (int i = 0; i < arr2.size(); i++)
    {
        prefix = calcPrefix(prefix, arr2[i]);
    }
    return prefix;
}

int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
{
    unordered_set<int> set;
    for (int i = 0; i < arr1.size(); i++)
    {
        int n = arr1[i];
        while (n > 0)
        {
            set.insert(n);
            n /= 10;
        }
    }
    int result = 0;
    for (int i = 0; i < arr2.size(); i++)
    {
        int n = arr2[i];
        while (n > result)
        {
            if (set.count(n))
            {
                result = n;
                break;
            }
            n /= 10;
        }
    }
    int res = 0;
    while (result > 0)
    {
        res++;
        result /= 10;
    }
    return res;
}