class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {

        int mat[n][n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mat[i][j] = 10000000;
            }
        }

        for (int i = 0; i < n; i++)
        {
            mat[i][i] = 0;
        }

        for (auto i : edges)
        {
            mat[i[0]][i[1]] = i[2];
            mat[i[1]][i[0]] = i[2];
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }

        int minThresh = INT_MAX;

        for (int i = 0; i < n; i++)
        {

            int result = 0;
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] <= distanceThreshold)
                {
                    result++;
                }
            }

            minThresh = min(minThresh, result);
        }

        int answer = 0;

        for (int i = 0; i < n; i++)
        {
            int result = 0;
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] <= distanceThreshold)
                {
                    result++;
                }
            }

            if (result == minThresh)
            {
                answer = i;
            }
        }
        return answer;
    }
};