#include <iostream>
#include <bits-stdc++.h>

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> graph(numCourses);
    vector<int> indeg(numCourses, 0);
    for (int i = 0; i < prerequisites.size(); i++)
    {
        graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        indeg[prerequisites[i][0]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++)
    {
        if (indeg[i] == 0)
            q.push(i);
    }
    int visited = 0;
    vector<int> result;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        visited++;
        result.push_back(curr);

        for (auto neighbor : graph[curr])
        {
            indeg[neighbor]--;
            if (indeg[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }
    return visited == numCourses ? result : vector<int>{};
}