#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = 1e9 + 7;
    int dp[3005][1005];
    int helper(int s, int e, int steps, map<pair<int, int>, int> &m)
    {
        if (steps == 0)
            return s == e;
        if (dp[s + 1000][steps] != -1)
            return dp[s + 1000][steps];

        int ans = 0;

        ans = (ans + helper(s + 1, e, steps - 1, m)) % mod;

        ans = (ans + helper(s - 1, e, steps - 1, m)) % mod;
        return dp[s + 1000][steps] = ans % mod;
    }
    int numberOfWays(int startPos, int endPos, int k)
    {
        map<pair<int, int>, int> m;
        memset(dp, -1, sizeof(dp));
        return helper(startPos, endPos, k, m);
    }
};

int main()
{
    int startPos = 1, endPos = 2, k = 3;
    Solution obj;
    cout << obj.numberOfWays(startPos, endPos, k) << endl;
    return 0;
}