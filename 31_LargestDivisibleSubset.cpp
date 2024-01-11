#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> dp(n, 1), hash(n);
        int maxi = 0, lastIndex = 0;
        for (int i = 1; i < n; i++)
        {
            hash[i] = i;
            for (int j = 0; j < i; j++)
            {
                if (arr[i] % arr[j] == 0 && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[i] + 1;
                    hash[i] = j;
                }
            }
            if (dp[i] > maxi)
            {
                maxi = dp[i];
                lastIndex = i;
            }
        }
        vector<int> temp;
        temp.push_back(arr[lastIndex]);
        while (hash[lastIndex] != lastIndex)
        {
            lastIndex = hash[lastIndex];
            temp.push_back(arr[lastIndex]);
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3};
    Solution s;
    vector<int> ans = s.largestDivisibleSubset(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}