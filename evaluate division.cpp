#include <iostream>
#include <bits-stdc++.h>

using namespace std;

double bfs(unordered_map<string, vector<pair<string, double>>> &graph, string start, string target)
{
    if (graph.find(start) == graph.end() || graph.find(target) == graph.end())
        return -1;
    queue<pair<string, double>> q;
    q.push({start, 1});
    map<string, bool> visited;
    visited[start] = true;
    while (!q.empty())
    {
        pair<string, double> curr = q.front();
        q.pop();

        if (curr.first == target)
            return curr.second;

        for (auto [node, distance] : graph[curr.first])
        {
            if (!visited[node])
            {
                visited[curr.first] = true;
                q.push({node, curr.second * distance});
            }
        }
    }
    return -1;
}

vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
{
    unordered_map<string, vector<pair<string, double>>> graph;
    for (int i = 0; i < equations.size(); i++)
    {
        graph[equations[i][0]].push_back({equations[i][1], values[i]});
        graph[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
    }
    vector<double> results;
    for (auto q : queries)
    {
        results.push_back(bfs(graph, q[0], q[1]));
    }
    return results;
}