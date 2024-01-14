#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValidSerialization(string s)
    {
        if (s[0] == '#')
        {
            if (s.size() == 1)
                return true;
            else
                return false;
        }

        stringstream ss(s);
        string word;
        int cnt = 1;

        while (!ss.eof())
        {
            getline(ss, word, ',');
            cnt -= 1;
            if (cnt < 0)
            {
                return false;
            }
            if (word != "#")
            {
                cnt += 2;
            }
        }
        if (cnt == 0)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    string s = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    Solution obj;
    cout << obj.isValidSerialization(s);

    return 0;
}