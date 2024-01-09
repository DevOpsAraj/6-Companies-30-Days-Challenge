#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int incremovableSubarrayCount(vector<int> &nums)
    {
        int size = nums.size();
        int right = size - 1;
        while (right && nums[right - 1] < nums[right])
        {
            right--;
        }

        if (right == 0)
        {
            return (long long)(1 + size) * size / 2;
        }

        long long ans = size - right + 1;
        for (int left = 0; left == 0 || nums[left - 1] < nums[left]; left++)
        {
            while (right < size && nums[left] >= nums[right])
            {
                right++;
            }
            ans += size - right + 1;
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Solution s;
    cout << s.incremovableSubarrayCount(nums) << endl;

    return 0;
}