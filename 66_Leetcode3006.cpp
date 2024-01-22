#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void kmp(string s, string t, vector<int> &result)
    {
        // build LPS
        int n = s.length(), m = t.length();
        vector<int> lps(m, 0);
        int len = 0, curr = 1;
        while (curr < m)
        {
            if (t[curr] == t[len])
                lps[curr++] = ++len;
            else
            {
                if (len)
                    len = lps[len - 1];
                else
                    lps[curr] = 0, curr = curr + 1;
            }
        }

        // Get matching indices
        int i = 0, j = 0;
        while ((n - i) >= (m - j))
        {
            if (s[i] == t[j])
                i++, j++;
            if (j == m)
                result.push_back(i - j), j = lps[j - 1];
            else if (i < n && s[i] != t[j])
            {
                if (j > 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
    }

    vector<int> beautifulIndices(string s, string a, string b, int k)
    {
        vector<int> a_pos, b_pos;
        vector<int> result;

        kmp(s, a, a_pos);
        kmp(s, b, b_pos);

        int j = 0;
        for (auto &a_ind : a_pos)
        {
            while (j < b_pos.size() && b_pos[j] < a_ind - k)
                j++;
            if (j < b_pos.size() && abs(b_pos[j] - a_ind) <= k)
                result.push_back(a_ind);
        }

        return result;
    }
};