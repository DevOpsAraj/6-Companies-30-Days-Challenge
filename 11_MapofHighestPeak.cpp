#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int n = isWater.size();
        int m = isWater[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> ans(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (isWater[i][j] == 1)
                {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }
        int dx_dy[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
        int level = 1;
        while (!q.empty())
        {
            int qSize = q.size();
            for (int c = 0; c < qSize; c++)
            {
                auto v = q.front();
                q.pop();
                int i = v.first;
                int j = v.second;
                for (auto ind : dx_dy)
                {
                    int newI = i + ind[0];
                    int newJ = j + ind[1];
                    if (newI >= 0 && newI < n && newJ >= 0 && newJ < m &&
                        ans[newI][newJ] == -1)
                    {
                        ans[newI][newJ] = level;
                        q.push({newI, newJ});
                    }
                }
            }
            level++;
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> isWater = {{0, 1}, {0, 0}};
    Solution s;
    vector<vector<int>> ans = s.highestPeak(isWater);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
    }

    return 0;
}