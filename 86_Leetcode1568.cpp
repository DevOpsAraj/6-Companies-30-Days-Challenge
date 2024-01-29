class Solution
{
public:
    int cnt = 0;
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int m, n;

    int minDays(vector<vector<int>> &grid)
    {
        m = grid.size(), n = grid[0].size();
        int comp = 0;
        vector<vector<int>> num(m, vector<int>(n)), low(m, vector<int>(n));
        bool hasJoin = false;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1 && num[i][j] == 0)
                {
                    ++comp;
                    dfs(i, j, -1, -1, grid, num, low, hasJoin);
                }
            }
        }
        // not 1 island
        if (comp != 1)
            return 0;
        // only one cell island -> just remove it
        if (cnt == 1)
            return 1;
        // if exist join -> remove join
        // else -> best way is remove 2 adj cell of corner
        return hasJoin ? 1 : 2;
    }
    void dfs(int i, int j, int pi, int pj, vector<vector<int>> &grid,
             vector<vector<int>> &num, vector<vector<int>> &low,
             bool &hasJoin)
    {
        low[i][j] = num[i][j] = ++cnt;
        int child = 0;
        for (auto &[x, y] : dir)
        {
            int ni = i + x, nj = j + y;
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == 1)
            {
                if (ni == pi && nj == pj)
                    continue;

                if (num[ni][nj] != 0)
                { // visited
                    low[i][j] = min(low[i][j], num[ni][nj]);
                }
                else
                {
                    ++child;
                    dfs(ni, nj, i, j, grid, num, low, hasJoin);
                    if (pi != -1 && pj != -1 && low[ni][nj] >= num[i][j])
                    {
                        hasJoin = true;
                    }
                    low[i][j] = min(low[i][j], low[ni][nj]);
                }
            }
        }
        if (pi == -1 && pj == -1 && child >= 2)
        {
            hasJoin = true;
        }
    }
};