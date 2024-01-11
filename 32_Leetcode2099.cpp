#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSubsequence1(vector<int> &nums, int k)
    {
        priority_queue<pair<int, int>> q;

        for (int i = 0; i < nums.size(); i++)
            q.push({nums[i], i});

        vector<int> ans(k);
        for (int i = 0; i < k; i++)
        {
            ans[i] = q.top().second;
            q.pop();
        }

        sort(ans.begin(), ans.end());

        for (int &i : ans)
            i = nums[i];

        return ans;
    }
    // SOLUTION Number 2
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); i++)
        {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end(),
             [&](const auto &a, const auto &b)
             { return a.first > b.first; });

        sort(v.begin(), v.begin() + k,
             [&](const auto &a, const auto &b)
             { return a.second < b.second; });

        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(v[i].first);
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {3, 4, 3, 3};
    int k = 2;

    Solution obj;
    vector<int> ans = obj.maxSubsequence(nums, k);
    for (int &i : ans)
        cout << i << " ";

    return 0;
}