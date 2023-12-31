#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string printMinNumberForPattern(string S)
    {
        int n = S.size();

        string ans = "";
        for (int i = 1; i <= n + 1; i++)
            ans += to_string(i);

        for (int i = 0; i < n; i++)
        {
            if (S[i] == 'I')
                continue;

            int cnt = 1;
            int k = i;
            while (i < n and S[i] == 'D')
            {
                cnt++;
                i++;
            }

            reverse(ans.begin() + k, ans.begin() + k + cnt);
        }

        return ans;
    }
};

int main()
{
    string s = "IIDDD";
    Solution obj;
    cout << obj.printMinNumberForPattern(s) << endl;
    return 0;
}