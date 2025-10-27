#include <iostream>
#include <bits-stdc++.h>

using namespace std;

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int x) : val(x) {};
};

vector<string> split(string s, char del)
{
    vector<string> res;
    stringstream ss(s);
    while (!ss.eof())
    {
        string word;
        getline(ss, word, del);
        res.push_back(word);
    }
    return res;
}

int main()
{
    tuple<int, int, int> cirko = {1, 2, 3};
    cout << get<1>(cirko);
    vector<tuple<int, int, int>> arr;
    arr.push_back(cirko);
    arr.push_back({5, 1, 9});
    arr.push_back({2, 5, 6});
    sort(arr.begin(), arr.end(), [](const tuple<int, int, int> &a, const tuple<int, int, int> &b)
         { return get<1>(a) < get<1>(b); });

    for (auto [a, b, c] : arr)
    {
        cout << "{" << a << "," << b << "," << c << "}" << endl;
    }
    set<pair<int, int>> set;
    auto it = set.upper_bound({1, 2});
    it = prev(it);
    set.erase(it);
    it = next(it);
    vector<int> niz = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << *upper_bound(niz.begin(), niz.end(), 5) << endl;
    cout << lower_bound(niz.begin(), niz.end(), 10) - niz.begin();
}