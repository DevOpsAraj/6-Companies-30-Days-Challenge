#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ans = 0;
    int dp[1 << 12][12][12];
    int help(string &s, int i, int j, int mask)
    {
        if (i >= j)
        {
            if (i == j && !(mask & (1 << i)))
                return 1;
            return 0;
        }

        if (dp[mask][i][j] != -1)
            return dp[mask][i][j];

        int a = 0;
        if ((mask & (1 << i)) || (mask & (1 << j)))
        {
            if ((mask & (1 << i)))
                a = max(a, help(s, i + 1, j, mask));
            if (mask & (1 << j))
                a = max(a, help(s, i, j - 1, mask));
        }
        else
        {
            if (s[i] == s[j])
                a = max(a, help(s, i + 1, j - 1, mask) + 2);
            a = max(a, help(s, i + 1, j, mask));
            a = max(a, help(s, i, j - 1, mask));
        }

        return dp[mask][i][j] = a;
    }
    void solve(string &s, int i, int j, int len, int mask)
    {
        if (i >= j)
        {
            int a = 0, n = 0;
            if (i == j)
            {
                a = 1;
                n = n | (1 << i);
            }
            if ((mask | n) != (1 << s.length()) - 1)
                ans =
                    max(ans, (len + a) * help(s, 0, s.length() - 1, mask | n));
            if (mask != (1 << s.length()) - 1)
                ans = max(ans, len * help(s, 0, s.length() - 1, mask));

            return;
        }

        if (s[i] == s[j])
        {
            int n = 0;
            n = n | (1 << i);
            n = n | (1 << j);
            solve(s, i + 1, j - 1, len + 2, mask | n);
        }

        solve(s, i + 1, j, len, mask);
        solve(s, i, j - 1, len, mask);

        return;
    }
    int maxProduct(string s)
    {
        int mask = 0;
        memset(dp, -1, sizeof dp);
        solve(s, 0, s.length() - 1, 0, mask);
        return ans;
    }
};

int main()
{
    string s = "aab";
    Solution obj;
    cout << obj.maxProduct(s) << endl;

    return 0;
}