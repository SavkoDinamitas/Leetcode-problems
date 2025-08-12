#include <iostream>
#include <bits-stdc++.h>

using namespace std;

bool isOperator(string s)
{
    return s == "+" || s == "-" || s == "/" || s == "*";
}

int evalRPN(vector<string> &tokens)
{
    stack<int> values;
    for (int i = 0; i < tokens.size(); i++)
    {
        if (!isOperator(tokens[i]))
        {
            values.push(stoi(tokens[i]));
        }
        else
        {
            int operand2 = values.top();
            values.pop();
            int operand1 = values.top();
            values.pop();
            if (tokens[i] == "+")
            {
                values.push(operand1 + operand2);
            }
            if (tokens[i] == "-")
            {
                values.push(operand1 - operand2);
            }
            if (tokens[i] == "*")
            {
                values.push(operand1 * operand2);
            }
            if (tokens[i] == "/")
            {
                values.push(operand1 / operand2);
            }
        }
    }
    return values.top();
}