#include <iostream>
#include <bits-stdc++.h>

using namespace std;

void calc(stack<int> &numbers, stack<char> &operations)
{
    if (!operations.empty() && operations.top() != '(')
    {
        int res = 0;
        if (operations.top() == '+')
            res = numbers.top();
        if (operations.top() == '-')
            res -= numbers.top();
        numbers.pop();
        res += numbers.top();
        numbers.pop();
        numbers.push(res);
        operations.pop();
    }
}

int calculate(string s)
{
    stack<char> operations;
    stack<int> numbers;

    int number = 0;
    bool n = true;
    char lastOperand = ' ';
    for (char c : s)
    {
        if (c >= '0' && c <= '9')
        {
            number *= 10;
            number += c - '0';
            n = true;
        }
        else
        {
            if (c == '+' || c == '-')
            {
                if (n)
                    numbers.push(number);
                calc(numbers, operations);
                operations.push(c);
                lastOperand = c;
                number = 0;
                n = false;
            }
            if (c == '(')
            {
                n = true;
                operations.push(c);
                lastOperand = c;
            }
            if (c == ')')
            {
                lastOperand = c;
                if (n)
                    numbers.push(number);
                n = false;
                number = 0;
                calc(numbers, operations);
                operations.pop();
            }
        }
    }
    if (lastOperand != ')')
    {
        numbers.push(number);
    }
    calc(numbers, operations);
    return numbers.top();
}

// signs solution
int calculate(string s)
{
    long result = 0;
    long number = 0;
    int sign = 1;
    stack<int> results, signs;

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (isdigit(c))
        {
            number = number * 10 + (c - '0');
        }
        else if (c == '+')
        {
            result += sign * number;
            number = 0;
            sign = 1;
        }
        else if (c == '-')
        {
            result += sign * number;
            number = 0;
            sign = -1;
        }
        else if (c == '(')
        {
            results.push(result);
            signs.push(sign);
            result = 0;
            sign = 1;
        }
        else if (c == ')')
        {
            result += sign * number;
            number = 0;
            result = results.top() + signs.top() * result;
            results.pop();
            signs.pop();
        }
    }
    result += sign * number;
    return result;
}

int main()
{
    string s = "  (  3 ) ";
    cout << endl
         << calculate(s) << endl;
}