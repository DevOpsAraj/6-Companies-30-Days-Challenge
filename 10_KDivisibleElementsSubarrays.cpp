#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countDistinct(vector<int> &nums, int k, int p)
    {
        int cnt[201] = {}, hash[201] = {}, res = 0;
        for (int sz = 0; sz < nums.size(); sz++)
        {
            unordered_set<int> s;
            for (int i = 0; i + sz < nums.size(); i++)
            {
                cnt[i] += nums[i + sz] % p == 0;
                if (cnt[i] <= k)
                {
                    hash[i] = ((long long)hash[i] * 200 + nums[i + sz]) % 1000000007;
                    res += s.insert(hash[i]).second;
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {2, 3, 3, 2, 2};
    int k = 2, p = 2;
    Solution s;
    cout << s.countDistinct(nums, k, p);
    return 0;
}