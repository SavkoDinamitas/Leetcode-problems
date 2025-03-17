#include <bits/stdc++.h>

using namespace std;

int knapSack(vector<int> &wt, int W)
{
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));

    // Build table dp[][] in bottom-up manner
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(wt[i - 1] + dp[i - 1][w - wt[i - 1]],
                               dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}

int xd(vector<int> process, int maks)
{
    vector<vector<bool>> dp(maks + 1, vector<bool>(process.size() + 1, false));
    int rez = 0;
    for (int i = 0; i <= maks; i++)
    {
        for (int j = 0; j <= process.size(); j++)
        {
            if (i == 0)
                dp[i][j] = true;
            else
            {
                bool ne = false;
                if (j - 1 >= 0)
                    ne = dp[i][j - 1];
                bool da = false;
                if (j - 1 >= 0 && i - process[j - 1] >= 0)
                {
                    da = dp[i - process[j - 1]][j - 1];
                }
                dp[i][j] = da || ne;

                if (dp[i][j])
                    rez = i;
            }
        }
    }
    return rez;
}

int main()
{
    vector<int> niz = {10, 17, 6, 2};
    while (true)
    {
        int w;
        cin >> w;
        cout << endl
             << xd(niz, w);
    }
}