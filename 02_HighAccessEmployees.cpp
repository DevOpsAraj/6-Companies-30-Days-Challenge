#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string>
    findHighAccessEmployees(vector<vector<string>> &access_times)
    {
        unordered_map<string, vector<int>> employeeAccess;

        for (const auto &access : access_times)
        {
            string employee = access[0];
            int time = stoi(access[1]);
            employeeAccess[employee].push_back(time);
        }

        vector<string> result;

        for (auto &entry : employeeAccess)
        {
            vector<int> &times = entry.second;
            sort(times.begin(), times.end());

            for (int i = 2; i < times.size(); i++)
            {
                if (times[i] - times[i - 2] < 100)
                {
                    result.push_back(entry.first);
                    break;
                }
            }
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());

        return result;
    }
};

int main()
{
    // access_times = [["a","0549"],["b","0457"],["a","0532"],["a","0621"],["b","0540"]]

    vector<vector<string>> access_times = {{"a", "0549"}, {"b", "0457"}, {"a", "0532"}, {"a", "0621"}, {"b", "0540"}};

    Solution obj;

    vector<string> ans = obj.findHighAccessEmployees(access_times);
    for (auto str : ans)
        cout << str << " ";

    return 0;
}