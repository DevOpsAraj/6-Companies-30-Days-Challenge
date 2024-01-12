#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int squareFreeSubsets(vector<int> &nums)
    {
        const int MOD = 1e9 + 7;
        vector<int> dp(1024, 0);
        int n = nums.size();
        vector<int> A = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

        dp[0] = 1;

        for (int i = 0; i < n; i++)
        {
            bool f = false;

            for (int j = 0; j < 10; j++)
            {
                if (nums[i] % (A[j] * A[j]) == 0)
                {
                    f = true;
                    break;
                }
            }

            if (f)
                continue;

            vector<int> nx(dp);
            int mask = 0;

            for (int j = 0; j < 10; j++)
            {
                if ((nums[i] % A[j]) == 0)
                    mask |= (1 << j);
            }

            for (int j = 0; j < 1024; j++)
            {
                if ((mask & j) == 0)
                    nx[mask | j] = (nx[mask | j] + dp[j]) % MOD;
            }

            dp.swap(nx);
        }

        int ans = -1;

        for (int i = 0; i < dp.size(); i++)
            ans = (ans + dp[i]) % MOD;

        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    Solution obj;
    cout << obj.squareFreeSubsets(nums) << endl;

    return 0;
}