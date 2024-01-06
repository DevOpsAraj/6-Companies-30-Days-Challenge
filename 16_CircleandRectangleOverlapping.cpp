#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1,
                      int x2, int y2)
    {
        int edgeX = (x_center < x1) ? x1 : (x_center > x2) ? x2
                                                           : x_center;
        int edgeY = (y_center < y1) ? y1 : (y_center > y2) ? y2
                                                           : y_center;
        int distX = x_center - edgeX, distY = y_center - edgeY;
        return distX * distX + distY * distY <= radius * radius;
    }
};

int main()
{
    int radius, x_center, y_center, x1, y1, x2, y2;
    cin >> radius >> x_center >> y_center >> x1 >> y1 >> x2 >> y2;
    Solution obj;
    bool ans = obj.checkOverlap(radius, x_center, y_center, x1, y1, x2, y2);
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}