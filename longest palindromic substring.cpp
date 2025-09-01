#include <iostream>
#include <bits-stdc++.h>

using namespace std;

// uh
string longestPalindrome(string s)
{
    int n = s.size();
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
    int maxi = 0;
    int pos;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int before = i > 0 && j > 0 ? dp[i - 1][j - 1] : 0;
            if (s[i] == s[n - j - 1])
                dp[i][j] = before + 1;
            if (dp[i][j] > maxi && n - j + dp[i][j] - 2 == i)
            {
                maxi = dp[i][j];
                pos = i;
            }
        }
    }
    string result = "";
    while (maxi-- > 0)
    {
        result += s[pos--];
    }
    return result;
}

// by length
string longestPalindrome(string s)
{
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = true;
    }
    int maxi = 1;
    int location = 0;
    int length = 2;
    while (length <= n)
    {
        for (int i = 0; i < n - length + 1; i++)
        {
            int j = i + length - 1;
            if (s[i] == s[j] && (dp[i + 1][j - 1] || length == 2))
            {
                dp[i][j] = true;
                maxi = length;
                location = i;
            }
        }
        length++;
    }
    return s.substr(location, maxi);
}

// O(n) ludnica
string longestPalindrome(string s)
{
    if (s.empty())
        return "";
    // Transform string: add separators to handle even-length cases
    string t = "^";
    for (char c : s)
    {
        t += "#" + string(1, c);
    }
    t += "#$";

    int n = t.size();
    vector<int> P(n, 0); // P[i] = radius of palindrome at i
    int center = 0, right = 0;
    int maxCenter = 0, maxLen = 0;

    for (int i = 1; i < n - 1; i++)
    {
        int mirror = 2 * center - i;

        if (i < right)
            P[i] = min(right - i, P[mirror]);

        // Expand around center i
        while (t[i + (1 + P[i])] == t[i - (1 + P[i])])
            P[i]++;

        // Update center and right boundary if we expanded past right
        if (i + P[i] > right)
        {
            center = i;
            right = i + P[i];
        }

        // Track the longest palindrome found so far
        if (P[i] > maxLen)
        {
            maxLen = P[i];
            maxCenter = i;
        }
    }

    // Find start index in original string
    int start = (maxCenter - maxLen) / 2;
    return s.substr(start, maxLen);
}