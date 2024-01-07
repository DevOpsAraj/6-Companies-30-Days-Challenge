#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int size = 0;
    vector<vector<int>> range;
    Solution(vector<vector<int>> &rects)
    {
        for (auto rect : rects)
        {
            vector<int> i;
            int dx = rect[2] - rect[0] + 1;
            int dy = rect[3] - rect[1] + 1;
            size += dx * dy;
            i.push_back(size);
            for (auto r : rect)
            {
                i.push_back(r);
            }
            range.push_back(i);
        }
    }

    vector<int> pick()
    {
        int idx = rand() % size;
        int rectIdx = 0;
        int l = 0, r = range.size();
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (range[mid][0] <= idx)
            {
                l = mid + 1;
            }
            else
            {
                rectIdx = mid;
                r = mid;
            }
        }
        int x = rangeRand(range[rectIdx][1], range[rectIdx][3]);
        int y = rangeRand(range[rectIdx][2], range[rectIdx][4]);
        vector<int> point = {x, y};
        return point;
    }
    int rangeRand(int x, int y)
    {
        int diff = y - x + 1;
        return x + (rand() % diff);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */