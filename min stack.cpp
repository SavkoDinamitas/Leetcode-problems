#include <iostream>
#include <bits-stdc++.h>

using namespace std;

class MinStack
{
private:
    stack<int> regular;
    stack<int> minimums;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        regular.push(val);
        if (minimums.empty() || minimums.top() > val)
        {
            minimums.push(val);
        }
    }

    void pop()
    {
        if (regular.top() == minimums.top())
            minimums.pop();
        regular.pop();
    }

    int top()
    {
        return regular.top();
    }

    int getMin()
    {
        return minimums.top();
    }
};