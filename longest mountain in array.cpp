#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int longestMountain(vector<int> &arr)
{
    bool up = false;
    int curr = 0;
    int result = 0;
    bool up_before = false;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i + 1] > arr[i])
        {
            if (up)
            {
                curr++;
            }
            else
            {
                if (up_before)
                    result = max(result, curr + 1);
                curr = 1;
                up = true;
                up_before = true;
            }
        }
        else if (arr[i + 1] < arr[i])
        {
            if (up)
            {
                up = false;
                curr++;
            }
            else
            {
                curr++;
            }
        }
        else
        {
            if (up)
            {
                up_before = false;
                up = false;
            }
            else
            {
                if (up_before)
                    result = max(result, curr + 1);
                up_before = false;
            }
        }
    }
    if (!up && up_before)
    {
        result = max(result, curr + 1);
    }
    return result;
}