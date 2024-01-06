#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int n, int k)
    {
        if (n == 1)
            return 0;
        else
        {
            return (solve(n - 1, k) + k) % n;
        }
    }
    int findTheWinner(int n, int k)
    {
        int ans = solve(n, k) + 1;
        return ans;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    Solution s;
    cout << s.findTheWinner(n, k) << endl;
    return 0;
}