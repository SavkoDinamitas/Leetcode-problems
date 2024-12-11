#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string convert(string s, int numRows)
{
    vector<int> firstrow;
    string res = "";
    if (numRows == 1)
        return s;
    for (int i = 0; i < s.length(); i += (numRows - 1) * 2)
    {
        res += s[i];
        firstrow.push_back(i);
    }
    firstrow.push_back(firstrow[firstrow.size() - 1] + (numRows - 1) * 2);

    for (int i = 1; i <= numRows - 2; i++)
    {
        for (int j = 0; j < firstrow.size(); j++)
        {
            if (firstrow[j] - i > 0 && firstrow[j] - i < s.size())
                res += s[firstrow[j] - i];
            if (firstrow[j] + i < s.size())
                res += s[firstrow[j] + i];
        }
    }
    for (int i = 0; i < firstrow.size(); i++)
    {
        if (firstrow[i] + numRows - 1 < s.size())
            res += s[firstrow[i] + numRows - 1];
    }
    return res;
}

int main()
{
}