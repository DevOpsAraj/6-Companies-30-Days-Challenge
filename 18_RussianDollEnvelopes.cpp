#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int LIS(vector<int> &height)
    {
        int n = height.size();
        if (n == 0)
            return 0;

        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (ans.empty() || height[i] > ans.back())
            {
                ans.push_back(height[i]);
            }
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), height[i]) -
                            ans.begin();
                ans[index] = height[i];
            }
        }
        return ans.size();
    }

    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        vector<pair<int, int>> data;
        int n = envelopes.size();
        for (int i = 0; i < n; i++)
        {
            data.push_back(make_pair(envelopes[i][0], envelopes[i][1]));
        }
        sort(data.begin(), data.end(),
             [](const pair<int, int> &a, const pair<int, int> &b)
             {
                 if (a.first == b.first)
                 {
                     return a.second > b.second;
                 }
                 else
                 {
                     return a.first < b.first;
                 }
             });

        vector<int> height;
        for (int i = 0; i < n; i++)
        {
            height.push_back(data[i].second);
        }
        return LIS(height);
    }
};

int main()
{
    vector<vector<int>> envelopes = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    Solution s;
    cout << s.maxEnvelopes(envelopes);
    return 0;
}