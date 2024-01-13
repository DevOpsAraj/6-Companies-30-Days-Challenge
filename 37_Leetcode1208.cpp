#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int n = s.length();
        int cost = 0;
        int left = 0, ans = 0;
        for (int right = 0; right < n; right++)
        {
            cost += abs(s[right] - t[right]);
            while (cost > maxCost)
            {
                cost -= abs(s[left] - t[left]);
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

int main()
{
    string s = "abcd", t = "bcdf";
    int maxCost = 3;
    Solution obj;
    cout << obj.equalSubstring(s, t, maxCost);

    return 0;
}