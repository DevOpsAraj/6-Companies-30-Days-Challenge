#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximizeSquareHoleArea(int h, int v, vector<int> &hBars,
                               vector<int> &vBars)
    {
        int conh = 0, conv = 0, cnth = 1, cntv = 1;

        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        for (int i = 1; i < hBars.size(); i++)
        {
            if (hBars[i - 1] + 1 == hBars[i])
            {
                cnth++;
            }
            else
            {
                conh = max(conh, cnth);
                cnth = 1;
            }
        }
        conh = max(conh, cnth);

        for (int i = 1; i < vBars.size(); i++)
        {
            if (vBars[i - 1] + 1 == vBars[i])
            {
                cntv++;
            }
            else
            {
                conv = max(conv, cntv);
                cntv = 1;
            }
        }
        conv = max(conv, cntv);

        int rem = min(conv, conh);

        return (rem + 1) * (rem + 1);
    }
};