#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int r0, int c0)
    {
        vector<vector<int>> ans;
        queue<pair<int, int>> q;
        q.push({r0, c0});

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        visited[r0][c0] = true;

        int dr[4] = {-1, 0, +1, 0};
        int dc[4] = {0, +1, 0, -1};

        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            ans.push_back({r, c});

            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nc >= 0 && nr < rows && nc < cols &&
                    !visited[nr][nc])
                {
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }
        return ans;
    }
};

int main()
{
    int rows = 1, cols = 2, rCenter = 0, cCenter = 0;
    Solution obj;
    vector<vector<int>> ans = obj.allCellsDistOrder(rows, cols, rCenter, cCenter);
    for (auto vec : ans)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    cout << "TEST CASE 2" << endl;
    rows = 2, cols = 2, rCenter = 0, cCenter = 1;
    ans = obj.allCellsDistOrder(rows, cols, rCenter, cCenter);
    for (auto vec : ans)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}