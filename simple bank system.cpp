#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Bank
{
    vector<long long> balance;
    int n;

public:
    Bank(vector<long long> &balance)
    {
        this->balance = balance;
        n = balance.size();
    }

    bool transfer(int account1, int account2, long long money)
    {
        if (account1 <= 0 || account1 > n || account2 <= 0 || account2 > n)
        {
            return false;
        }
        if (balance[account1 - 1] >= money)
        {
            balance[account1 - 1] -= money;
            balance[account2 - 1] += money;
            return true;
        }
        return false;
    }

    bool deposit(int account, long long money)
    {
        if (account <= 0 || account > n)
        {
            return false;
        }
        balance[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money)
    {
        if (account <= 0 || account > n)
        {
            return false;
        }
        if (balance[account - 1] >= money)
        {
            balance[account - 1] -= money;
            return true;
        }
        return false;
    }
};