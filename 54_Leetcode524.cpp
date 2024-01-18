#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string findLongestWord(string s, vector<string> &dictionary)
    {
        int n = dictionary.size();
        sort(dictionary.begin(), dictionary.end());
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            int first = 0, second = 0;
            while (first < s.size() && second < dictionary[i].size())
            {
                if (s[first] == dictionary[i][second])
                {
                    first++;
                    second++;
                }
                else
                {
                    first++;
                }
            }
            if (second >= dictionary[i].size() &&
                dictionary[i].size() > ans.size())
            {
                ans = dictionary[i];
            }
        }
        return ans;
    }
};

int main()
{
    string s = "abpcplea";
    vector<string> dictionary = {"ale", "apple", "monkey", "plea"};
    Solution obj;
    cout << obj.findLongestWord(s, dictionary);

    return 0;
}