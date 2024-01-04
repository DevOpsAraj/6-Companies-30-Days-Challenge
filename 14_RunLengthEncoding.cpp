#include <bits/stdc++.h>
using namespace std;

string encode(string src)
{
    string ans = "";
    int count = 1;
    for (int i = 1; i <= src.size(); i++)
    {
        if (src[i - 1] != src[i])
        {
            ans += src[i - 1];
            ans += to_string(count);
            count = 1;
        }
        else
        {
            count += 1;
        }
    }
    return ans;
}

int main()
{
    string str;
    cin >> str;

    cout << encode(str) << endl;
    return 0;
}