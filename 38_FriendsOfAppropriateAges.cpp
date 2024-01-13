#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numFriendRequests(vector<int> &ages)
    {
        int ans = 0;
        vector<int> cnt(121, 0);
        for (int x : ages)
        {
            ++cnt[x];
        }

        for (int i = 0; i < 121; ++i)
        {
            for (int j = 0; j < 121; ++j)
            {
                if (request(i, j))
                {
                    if (i != j)
                    {
                        ans += cnt[i] * cnt[j];
                    }
                    else
                    {
                        ans += cnt[i] * (cnt[i] - 1);
                    }
                }
            }
        }
        return ans;
    }

    bool request(int x, int y)
    {
        if (y <= 0.5 * x + 7)
            return false;
        if (y > x)
            return false;
        if (y > 100 && x < 100)
            return false;
        return true;
    }
};

int main()
{
    vector<int> ages = {16, 16};
    Solution s;
    cout << s.numFriendRequests(ages) << endl;

    return 0;
}