#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int maxi = INT_MIN;
    int pos = -1;
    int rezervoar = 0;
    for (int i = gas.size() - 1; i >= 0; i--)
    {
        rezervoar += gas[i] - cost[i];
        if (rezervoar > maxi)
        {
            maxi = rezervoar;
            pos = i;
        }
    }
    if (gas[gas.size() - 1] - cost[cost.size() - 1] + rezervoar > maxi)
        pos = gas.size() - 1;

    rezervoar = 0;
    for (int i = pos; i < gas.size(); i++)
    {
        rezervoar += gas[i] - cost[i];
        if (rezervoar < 0)
            return -1;
    }
    for (int i = 0; i <= pos; i++)
    {
        rezervoar += gas[i] - cost[i];
        if (rezervoar < 0)
            return -1;
    }
    return pos;
}

int main()
{
}