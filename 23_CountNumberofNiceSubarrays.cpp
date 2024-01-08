#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        vector<int> odd;
        int n = nums.size(), ans = 0;
        odd.push_back(-1);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] & 1)
                odd.push_back(i);
        }
        odd.push_back(n);
        for (int i = 1; i + k < odd.size(); i++)
        {
            ans += (odd[i] - odd[i - 1]) * (odd[i + k] - odd[i + k - 1]);
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    int k = 2;
    Solution s;
    cout << s.numberOfSubarrays(nums, k) << endl;
    return 0;
}