#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int dfs(int mask, int last, int n, vector<int> &nums, int &mod,
            vector<vector<int>> &dp)
    {
        if (mask == (1 << n) - 1)
            return 1;
        if (dp[mask][last] != -1)
            return dp[mask][last];

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if ((nums[i] % nums[last] == 0 || nums[last] % nums[i] == 0) &&
                (mask & (1 << i)) == 0)
            {
                mask |= (1 << i);
                ans = (ans + dfs(mask, i, n, nums, mod, dp)) % mod;
                mask &= ~(1 << i);
            }
        }
        return dp[mask][last] = ans;
    }

public:
    int specialPerm(vector<int> &nums)
    {
        int n = nums.size();
        int mod = 1e9 + 7;
        int ans = 0;
        vector<vector<int>> dp(1 << n, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
        {
            int mask = 0;
            mask |= (1 << i);
            ans = (ans + dfs(mask, i, n, nums, mod, dp)) % mod;
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {2, 3, 6};
    Solution obj;
    cout << obj.specialPerm(nums) << endl;

    return 0;
}