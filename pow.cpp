#include <iostream>
#include <bits-stdc++.h>

using namespace std;

double pow(double x, int n)
{
    if (n == 1)
        return x;
    if (n % 2 == 0)
    {
        double h = pow(x, n / 2);
        return h * h;
    }
    else
    {
        double h = pow(x, (n - 1) / 2);
        return x * h * h;
    }
}

int main()
{
    cout << endl
         << pow(2, 4);
}