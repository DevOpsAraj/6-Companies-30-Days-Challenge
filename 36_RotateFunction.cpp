#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int n = nums.size();

        int sum = 0;
        int currState = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            currState += i * nums[i];
        }

        int ans = currState;
        for (int i = n - 1; i >= 0; i--)
        {
            currState += (sum - (n * nums[i]));
            ans = max(ans, currState);
        }

        return ans;
    }
};

int main()
{
    vector<int> nums = {4, 3, 2, 6};
}