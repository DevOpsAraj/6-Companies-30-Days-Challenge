#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solve(string digits, string ds, int index, vector<string> &ans, string mapping[])
    {
        if (index >= digits.length())
        {
            ans.push_back(ds);
            return;
        }
        int num = digits[index] - '0';
        string val = mapping[num];

        for (int i = 0; i < val.length(); i++)
        {
            ds.push_back(val[i]);
            solve(digits, ds, index + 1, ans, mapping);
            ds.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        if (digits.length() == 0)
            return ans;

        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string ds;
        int index = 0;
        solve(digits, ds, index, ans, mapping);
        return ans;
    }
};

int main()
{
    string digits = "23";
    Solution obj;
    vector<string> ans = obj.letterCombinations(digits);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}