#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int myAtoi(string s)
{
    long long result = 0;
    int sign = 1;
    int i = 0;
    while (i < s.size() && s[i] == ' ')
    {
        i++;
    }
    if (i < s.size() && (s[i] == '+' || s[i] == '-'))
    {
        if (s[i] == '-')
            sign = -1;
        i++;
    }
    while (s[i] >= '0' && s[i] <= '9')
    {
        int digit = s[i] - '0';

        if (result > (LLONG_MAX - digit) / 10)
        {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        result = result * 10 + digit;
        i++;
    }

    result *= sign;
    if (result > INT_MAX)
        return INT_MAX;
    if (result < INT_MIN)
        return INT_MIN;

    return result;
}