#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        int n = nums.size();
        priority_queue<int> q(nums.begin(), nums.end());
        for (int i = 1; i < n; i += 2)
        {
            nums[i] = q.top();
            q.pop();
        }
        for (int i = 0; i < n; i += 2)
        {
            nums[i] = q.top();
            q.pop();
        }
    }
};

int main()
{
    vector<int> nums = {1, 5, 1, 1, 6, 4};
    Solution s;
    s.wiggleSort(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}