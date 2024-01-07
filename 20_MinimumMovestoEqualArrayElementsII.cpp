#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        int n = nums.size(), steps = 0;
        sort(nums.begin(), nums.end());
        int median = nums[n / 2];
        for (int i = 0; i < n; i++)
        {
            steps += abs(nums[i] - median);
        }
        return steps;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3};
    Solution s;
    cout << s.minMoves2(nums) << endl;

    vector<int> nums2 = {1, 10, 2, 9};
    cout << s.minMoves2(nums2) << endl;

    return 0;
}