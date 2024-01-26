#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool asteroidsDestroyed(int mass, vector<int> &asteroids)
    {
        sort(asteroids.begin(), asteroids.end());
        long long ans = mass;
        for (auto it : asteroids)
        {
            if (ans >= it)
                ans += it;
            else
                return false;
        }
        return true;
    }
};