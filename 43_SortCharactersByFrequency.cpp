#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool static cmp(pair<char, int> &a, pair<char, int> &b)
    {
        return a.second > b.second;
    }
    string frequencySort(string s)
    {
        unordered_map<char, int> mp;
        vector<pair<char, int>> vec;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        vector<pair<char, int>> v(mp.begin(), mp.end());

        sort(v.begin(), v.end(), cmp);

        string ans;

        for (auto x : v)
        {
            ans.append(x.second, x.first);
        }
        return ans;
    }
};
