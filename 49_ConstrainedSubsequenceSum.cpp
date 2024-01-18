#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int constrainedSubsetSum(vector<int> &nums, int k)
    {
        deque<int> q;
        int ans = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            if (q.size() > 0)
            {
                int t = max(nums[i], nums[q.front()] + nums[i]);
                nums[i] = t;
                ans = max(ans, t);
                while (q.size() and nums[q.back()] <= t)
                {
                    q.pop_back();
                }
                q.push_back(i);
            }
            else
            {
                q.push_back(i);
                ans = max(ans, nums[i]);
            }
            if (i - q.front() >= k)
                q.pop_front();
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {10, 2, -10, 5, 20};
    int k = 2;

    Solution s;
    cout << s.constrainedSubsetSum(nums, k);

    return 0;
}