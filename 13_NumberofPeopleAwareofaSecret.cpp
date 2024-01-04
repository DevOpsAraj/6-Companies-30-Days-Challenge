#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int n, int delay, int forget)
    {
        queue<pair<int, int>> share;
        queue<pair<int, int>> death;
        share.push({1, delay});
        death.push({1, forget});
        int temp = 0;
        int mod = 1e9 + 7;
        for (int i = 1; i < n; i++)
        {
            if (share.front().second == i)
            {
                temp = (temp + share.front().first) % mod;
                share.pop();
            }
            if (death.front().second == i)
            {
                temp = (mod + temp - death.front().first) % mod;
                death.pop();
            }
            if (temp != 0)
            {
                share.push({temp, i + delay});
                death.push({temp, i + forget});
            }
        }
        int ans = 0;
        while (!death.empty())
        {
            ans = (ans + death.front().first) % mod;
            death.pop();
        }
        return ans;
    }

    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        return solve(n, delay, forget);
    }
};

int main()
{
    int n = 6, delay = 2, forget = 4;
    Solution obj;
    cout << obj.peopleAwareOfSecret(n, delay, forget) << endl;
    n = 4, delay = 1, forget = 3;
    cout << obj.peopleAwareOfSecret(n, delay, forget) << endl;
    n = 5, delay = 1, forget = 2;
    cout << obj.peopleAwareOfSecret(n, delay, forget) << endl;
    n = 5, delay = 1, forget = 1;
    cout << obj.peopleAwareOfSecret(n, delay, forget) << endl;
    return 0;
}