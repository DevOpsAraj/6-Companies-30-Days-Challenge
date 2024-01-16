#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestString(int x, int y, int z)
    {
        return 2 * (min(x, y) * 2 + z + (x != y));
    }
};

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    Solution obj;
    cout << obj.longestString(x, y, z) << endl;

    return 0;
}