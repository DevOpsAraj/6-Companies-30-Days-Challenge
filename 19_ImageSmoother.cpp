#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int n = img.size(), m = img[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                int sum = 0, cnt = 0;
                for (int dx = -1; dx <= 1; ++dx)
                {
                    for (int dy = -1; dy <= 1; ++dy)
                    {
                        int nx = dx + i, ny = dy + j;
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                            continue;
                        ++cnt;
                        sum += img[nx][ny];
                    }
                }
                ans[i][j] = sum / cnt;
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> img = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    Solution s;
    vector<vector<int>> ans = s.imageSmoother(img);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }

        cout << endl;
    }
    return 0;
}