#include <iostream>
#include <bits-stdc++.h>

using namespace std;

int reverseBits(int n)
{
    unsigned int result;
    for (int i = 0; i < 32; i++)
    {
        result <<= 1;
        result |= (n & 1);
        n >>= 1;
    }
    return result;
}