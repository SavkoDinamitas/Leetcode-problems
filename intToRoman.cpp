#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string intToRoman(int num)
{
    vector<int> arabic = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string result = "";
    while (num > 0)
    {
        int i = 0;
        while (arabic[i] > num)
            i++;
        result += roman[i];
        num -= arabic[i];
    }
    return result;
}

int main()
{
}