#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[1001][1001];

    int mcm(string &s, unordered_set<string> &st, int i, int j)
    {
        if (i > j)
            return 0;

        if (st.find(s.substr(i, j - i + 1)) != st.end())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = j - i + 1;

        for (int idx = i; idx < j; idx++)
        {
            ans = min(ans, mcm(s, st, i, idx) + mcm(s, st, idx + 1, j));
        }
        return dp[i][j] = ans;
    }

    int minExtraChar(string s, vector<string> &dictionary)
    {
        unordered_set<string> st;
        for (auto it : dictionary)
            st.insert(it);

        memset(dp, -1, sizeof(dp));
        return mcm(s, st, 0, s.size() - 1);
    }
};

int main()
{
    string s = "leetcode";
    vector<string> dictionary = {"leet", "code"};
    Solution obj;
    cout << obj.minExtraChar(s, dictionary);

    return 0;
}