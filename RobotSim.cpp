#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/walking-robot-simulation/submissions/1379290733/?envType=daily-question&envId=2024-09-04
*/

int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
{
    set<vector<int>> obs;
    for (int i = 0; i < obstacles.size(); i++)
    {
        obs.insert(obstacles[i]);
    }
    int directionsX[4] = {0, 1, 0, -1};
    int directionsY[4] = {1, 0, -1, 0};
    int facing = 0;
    int result = 0;
    int sx = 0;
    int sy = 0;
    for (int i = 0; i < commands.size(); i++)
    {
        if (commands[i] == -1)
        {
            facing = (facing + 1) % 4;
        }
        else if (commands[i] == -2)
        {
            facing = (facing + 3) % 4;
        }
        else
        {
            for (int j = 0; j < commands[i]; j++)
            {
                int nx = sx + directionsX[facing];
                int ny = sy + directionsY[facing];
                vector<int> pos = {nx, ny};
                if (obs.find(pos) == obs.end())
                {
                    sx = nx;
                    sy = ny;
                    result = max(result, sx * sx + sy * sy);
                }
            }
        }
    }
    return result;
}

int main()
{
    vector<int> commands;
    vector<int> obstacles;
    cout << "Hello world!" << endl;
    return 0;
}
