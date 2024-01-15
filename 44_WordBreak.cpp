#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int dp[s.size()];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < s.size(); ++i)
        {
            for (string &word : wordDict)
            {
                int start = (i + 1) - word.size();
                int end = start + word.size() - 1;
                if (start < 0 || (start != 0 && !dp[start - 1]))
                    continue;

                if (start == 0 || dp[start - 1] == 1)
                {
                    bool compare = true;
                    for (int j = 0; j < word.size(); ++j)
                    {
                        if (s[j + start] != word[j])
                        {
                            compare = false;
                            break;
                        }
                    }

                    if (compare)
                        dp[end] = 1;
                }
            }
        }
        return dp[s.size() - 1];
    }
};

int main()
{
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    Solution obj;
    cout << obj.wordBreak(s, wordDict);

    return 0;
}