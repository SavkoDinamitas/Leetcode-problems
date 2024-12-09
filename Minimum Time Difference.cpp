#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*https://leetcode.com/problems/minimum-time-difference/description/?envType=daily-question&envId=2024-09-16*/

int findMinDifference(vector<string> &timePoints)
{
    vector<int> times;
    for (int i = 0; i < timePoints.size(); i++)
    {
        int h = stoi(timePoints[i].substr(0, 2));
        int m = stoi(timePoints[i].substr(3, 2));
        times.push_back(h * 60 + m);
    }

    sort(times.begin(), times.end());

    int minDif = INT_MAX;
    for (int i = 1; i < times.size(); i++)
    {
        minDif = min(minDif, times[i] - times[i - 1]);
    }
    minDif = min(minDif, 24 * 60 - times[times.size() - 1] + times[0]);
    return minDif;
}

int main()
{
    vector<string> time;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string xd;
        cin >> xd;
        time.push_back(xd);
    }
    cout << findMinDifference(time);
}