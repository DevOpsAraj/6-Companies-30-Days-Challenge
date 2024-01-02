#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void findCombination(int k, int n, vector<int> &temp, vector<vector<int>> &ans)
    {
        // Base Case
        if (temp.size() == k && n == 0)
        {
            ans.push_back(temp);
            return;
        }

        if (temp.size() < k)
        {
            for (int i = temp.empty() ? 1 : temp.back() + 1; i <= 9; i++)
            {
                if (n - i < 0)
                    break;

                temp.push_back(i);
                findCombination(k, n - i, temp, ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> temp;

        findCombination(k, n, temp, ans);
        return ans;
    }
};

int main()
{
    int k, n;
    cin >> k >> n;
    Solution obj;
    vector<vector<int>> ans = obj.combinationSum3(k, n);
    for (auto it : ans)
    {
        for (int i = 0; i < it.size(); i++)
            cout << it[i] << " ";
        cout << endl;
    }
    return 0;
}