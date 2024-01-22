#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        int count = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for (int i = 0, j = 0; i < g.size() && j < s.size(); j++)
        {
            if (g[i] <= s[j])
            {
                count++;
                i++;
            }
        }
        return count;
    }
};

int main()
{
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};
    Solution obj;
    cout << obj.findContentChildren(g, s);
    return 0;
}