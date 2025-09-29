#include <iostream>
#include <bits-stdc++.h>

using namespace std;

// this does not handle duplicates in words :(
vector<int> findSubstring(string s, vector<string> &words)
{
    unordered_map<string, int> map;
    for (int i = 0; i < words.size(); i++)
    {
        map[words[i]] = i + 1;
    }
    vector<int> beg(s.size(), -1);
    int n = words[0].size();
    deque<char> window;

    for (int i = 0; i < n - 1; i++)
    {
        window.push_back(s[i]);
    }

    for (int i = n - 1; i < s.size(); i++)
    {
        window.push_back(s[i]);
        string curr(window.begin(), window.end());
        if (map[curr] > 0)
        {
            beg[i + 1 - n] = map[curr];
        }
        window.pop_front();
    }
    unordered_set<int> set;
    vector<int> result;
    for (int i = 0; i < s.size(); i++)
    {
        set.clear();
        int j = i;
        while (j < s.size() && beg[j] != -1)
        {
            if (set.insert(beg[j]).second)
            {
                j += n;
                if (set.size() == words.size())
                {
                    result.push_back(i);
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    return result;
}

// valid solution
vector<int> findSubstring(string s, vector<string> &words)
{
    vector<int> result;
    int wordLen = words[0].size();
    int wordCount = words.size();
    int totalSize = wordLen * wordCount;

    unordered_map<string, int> wordFreq;
    for (auto &word : words)
        wordFreq[word]++;

    for (int offset = 0; offset < wordLen; offset++)
    {
        int left = offset, count = 0;
        unordered_map<string, int> window;
        for (int right = offset; right + wordLen <= s.length(); right += wordLen)
        {
            string w = s.substr(right, wordLen);

            if (wordFreq.count(w))
            {
                window[w]++;
                count++;

                while (window[w] > wordFreq[w])
                {
                    string leftWord = s.substr(left, wordLen);
                    window[leftWord]--;
                    left += wordLen;
                    count--;
                }

                if (wordCount == count)
                {
                    result.push_back(left);
                }
            }
            else
            {
                window.clear();
                count = 0;
                left = right + wordLen;
            }
        }
    }

    return result;
}

// rolling hash solution O(n)
struct RollingHash
{
    vector<long long> prefix, power;
    long long base, mod;

    RollingHash(const string &s, long long base = 131,
                long long mod = 1e9 + 7)
        : base(base), mod(mod)
    {
        int n = s.size();
        prefix.assign(n + 1, 0);
        power.assign(n + 1, 1);

        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = (prefix[i] * base + s[i]) % mod;
            power[i + 1] = (power[i] * base) % mod;
        }
    }

    long long get(int l, int r)
    {
        long long h = (prefix[r + 1] - prefix[l] * power[r - l + 1]) % mod;
        if (h < 0)
            h += mod;
        return h;
    }
};

vector<int> findSubstring(string s, vector<string> &words)
{
    vector<int> result;
    if (s.empty() || words.empty())
        return result;

    int wordLen = words[0].size();
    int wordCount = words.size();
    int totalSize = wordLen * wordCount;

    if (s.size() < totalSize)
        return result;

    RollingHash rh_s(s);
    unordered_map<long long, int> wordFreq;
    for (auto &w : words)
    {
        RollingHash rh_w(w);
        long long h = rh_w.get(0, wordLen - 1);
        wordFreq[h]++;
    }

    for (int offset = 0; offset < wordLen; offset++)
    {
        int left = offset, count = 0;
        unordered_map<long long, int> window;

        for (int right = offset; right + wordLen <= (int)s.size();
             right += wordLen)
        {
            long long h = rh_s.get(right, right + wordLen - 1);

            if (wordFreq.count(h))
            {
                window[h]++;
                count++;

                while (window[h] > wordFreq[h])
                {
                    long long leftHash = rh_s.get(left, left + wordLen - 1);
                    window[leftHash]--;
                    left += wordLen;
                    count--;
                }

                if (count == wordCount)
                {
                    result.push_back(left);
                }
            }
            else
            {
                window.clear();
                count = 0;
                left = right + wordLen;
            }
        }
    }

    return result;
}