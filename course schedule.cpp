#include <iostream>
#include <bits-stdc++.h>

using namespace std;

bool loop(vector<vector<int>> &graph, int curr, vector<char> &visited)
{
    if (visited[curr] == '#')
        return true;
    if (visited[curr] == 'O')
        return false;
    visited[curr] = '#';
    for (int i = 0; i < graph[curr].size(); i++)
    {
        if (loop(graph, graph[curr][i], visited))
            return true;
    }
    visited[curr] = 'O';
    return false;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> graph(numCourses);
    for (int i = 0; i < prerequisites.size(); i++)
    {
        graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
    vector<char> visited(numCourses, 'X');
    for (int i = 0; i < numCourses; i++)
    {
        if (visited[i] == 'X' && loop(graph, i, visited))
            return false;
    }
    return true;
}