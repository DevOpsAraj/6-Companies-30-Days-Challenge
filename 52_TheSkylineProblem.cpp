#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        int n = buildings.size();
        vector<vector<int>> ans;
        multiset<int> pq;
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++)
        {
            int x1 = buildings[i][0], x2 = buildings[i][1], h = buildings[i][2];
            arr.push_back({x1, -h});
            arr.push_back({x2, h});
        }
        sort(arr.begin(), arr.end());
        int sz = arr.size();
        pq.insert(0);
        int currHeight = 0;
        for (int i = 0; i < sz; i++)
        {
            int x = arr[i].first;
            int h = arr[i].second;

            if (h < 0)
            {
                pq.insert(-h);
                if (*pq.rbegin() != currHeight)
                {
                    currHeight = *pq.rbegin();
                    ans.push_back({x, currHeight});
                }
            }
            else
            {
                pq.erase(pq.find(h));
                if (currHeight != *pq.rbegin())
                {
                    currHeight = *pq.rbegin();
                    ans.push_back({x, currHeight});
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    Solution obj;
    vector<vector<int>> ans = obj.getSkyline(buildings);
    for (auto vec : ans)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }

    return 0;
}