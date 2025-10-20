#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int finalValueAfterOperations(vector<string> &operations)
{
    int result = 0;
    for (auto command : operations)
    {
        if (command == "--X")
        {
            result--;
            continue;
        }
        if (command == "X--")
        {
            result--;
            continue;
        }
        if (command == "++X")
        {
            result++;
            continue;
        }
        if (command == "X++")
        {
            result++;
            continue;
        }
    }
    return result;
}