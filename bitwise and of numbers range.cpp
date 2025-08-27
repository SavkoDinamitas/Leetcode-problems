#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int rangeBitwiseAnd(int left, int right)
{
    unsigned int mask = 1U << 31;
    unsigned int result = 0;

    if (left == right)
        return left;

    while ((left & mask) == (right & mask) && mask != 0)
    {
        if (left & mask)
            result |= mask;
        mask >>= 1;
    }
    return result;
}

// ragebait
int rangeBitwiseAnd(int left, int right)
{
    int shift = 0;
    while (left < right)
    {
        left >>= 1;
        right >>= 1;
        shift++;
    }
    return left << shift;
}