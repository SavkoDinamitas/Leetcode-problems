#include <iostream>
#include <bits-stdc++.h>

using namespace std;

string simplifyPath(string path)
{
    vector<string> stack;
    string word = "";
    string result = "";
    path += "/";
    for (int i = 0; i < path.length(); i++)
    {
        if (path[i] == '/' && word != "")
        {
            if (word == ".." && !stack.empty())
            {
                stack.pop_back();
            }

            if (word != "." && word != "..")
                stack.push_back(word);
            word = "";
        }
        else if (path[i] != '/')
        {
            word += path[i];
        }
    }

    for (int i = 0; i < stack.size(); i++)
    {
        result += "/" + stack[i];
    }

    return result == "" ? "/" : result;
}