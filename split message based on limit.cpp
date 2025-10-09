#include <iostream>
#include <bits-stdc++.h>

using namespace std;

class Solution
{
public:
    bool canSplit(string message, int limit, int parts)
    {
        int l = 0;
        int p = parts;
        while (p > 0)
        {
            l++;
            p /= 10;
        }
        int possible = (limit - 2 * l - 3) * parts;
        int a = 10;
        while (a <= parts)
        {
            possible += a - 1;
            a *= 10;
        }
        return possible >= (int)message.length();
    }
    // it doesn't always mean that if a > b and canSplit(b) => canSplit(a)!!!
    int binarySearchBySolution(string message, int limit)
    {
        /*int l = 0;
        int r = message.length();

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (canSplit(message, limit, m)) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return l;*/
        for (int i = 1; i <= message.size(); i++)
        {
            if (canSplit(message, limit, i))
                return i;
        }
        return message.size() + 1;
    }

    vector<string> splitMessage(string message, int limit)
    {
        int parts = binarySearchBySolution(message, limit);
        if (parts > message.length() || parts == 0)
            return {};
        int curr = 1;
        vector<string> result;
        int p = 0;
        while (curr <= parts)
        {
            string s = "";
            int len = limit - 3 - to_string(curr).length() -
                      to_string(parts).length();
            s += message.substr(p, min(len, (int)message.size() - p));
            p += len;
            s += "<" + to_string(curr) + "/" + to_string(parts) + ">";
            result.push_back(s);
            curr++;
        }
        return result;
    }
};