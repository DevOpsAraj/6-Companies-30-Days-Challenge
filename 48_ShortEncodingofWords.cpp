#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumLengthEncoding(vector<string> &words)
    {
        unordered_set<string> s(words.begin(), words.end());
        int res = 0;

        for (int i = 0; i < words.size(); i++)
            for (int j = 1; j < words[i].size(); j++)
                s.erase(words[i].substr(j));

        for (auto x : s)
            res += x.size() + 1;
        return res;
    }
};

int main()
{
    vector<string> words = {"time", "me", "bell"};
    Solution s;
    cout << s.minimumLengthEncoding(words);
    return 0;
}