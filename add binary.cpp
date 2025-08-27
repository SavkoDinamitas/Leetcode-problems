#include <iostream>
#include <bits-stdc++.h>

using namespace std;

string addBinary(string a, string b)
{
    string result = "";
    int up = a.size() - 1;
    int down = b.size() - 1;
    int next = 0;
    while (up >= 0 || down >= 0)
    {
        char left = up >= 0 ? a[up] : '0';
        char right = down >= 0 ? b[down] : '0';

        int res = left + right - 2 * '0' + next;
        result = (char)(res % 2 + '0') + result;
        next = res / 2;
        up--;
        down--;
    }
    if (next > 0)
        result = '1' + result;
    return result;
}