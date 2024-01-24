#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countCollisions(string d)
    {
        int left = 0, right = 0, st = 0;
        bool isR = false;
        int collision = 0;

        for (int i = 0; i < d.size(); i++)
        {
            if (d[i] == 'L')
            {
                if (isR && right != 0)
                {
                    collision += 2;
                    right--;
                    collision += right;
                    right = 0;
                    isR = false;
                    st++;
                }
                else if (!isR && st != 0)
                {
                    collision++;
                }
                else
                    left++;
            }
            else if (d[i] == 'S')
            {
                if (right != 0)
                {
                    collision += right;
                    right = 0;
                }
                isR = false;
                st++;
            }
            else
            {
                isR = true;
                right++;
            }
        }

        return collision;
    }
};