class Solution
{
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums,
                                       vector<vector<int>> &queries)
    {
        vector<vector<int>> v(10);
        int n = nums.size();
        vector<int> arr(n);
        int y = 1;
        vector<vector<int>> trim(nums[0].size() + 1);
        for (int i = 0; i < n; i++)
            arr[i] = i;

        for (int j = nums[0].size() - 1; j >= 0; j--)
        {
            for (int i : arr)
            {
                v[nums[i][j] - '0'].push_back(i);
            }
            int x = 0;
            for (int i = 0; i < 10; i++)
            {
                for (auto k : v[i])
                {
                    arr[x++] = k;
                }
                v[i].clear();
            }
            trim[y++] = arr;
        }
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            ans.push_back(trim[queries[i][1]][queries[i][0] - 1]);
        }
        return ans;
    }
};