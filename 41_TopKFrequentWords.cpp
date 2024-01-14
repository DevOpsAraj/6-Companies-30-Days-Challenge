#include <bits/stdc++.h>
using namespace std;

struct myComp
{
    bool operator()(pair<int, string> const &a, pair<int, string> const &b)

    {
        if (a.first == b.first)
            return a.second < b.second;
        else
            return a.first > b.first;
    }
};
class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> mp;
        for (int i = 0; i < words.size(); i++)
        {
            mp[words[i]]++;
        }
        vector<string> ans(k);
        priority_queue<pair<int, string>, vector<pair<int, string>>, myComp> pq;

        for (auto i : mp)
        {
            if (pq.size() < k)
            {
                pq.push({i.second, i.first});
            }
            else
            {
                if (pq.top().first < i.second)
                {
                    pq.pop();
                    pq.push({i.second, i.first});
                }
                else if (pq.top().first == i.second)
                {
                    if (pq.top().second > i.first)
                    {
                        pq.pop();
                        pq.push({i.second, i.first});
                    }
                }
            }
        }
        k--;
        while (!pq.empty())
        {
            pair<int, string> t = pq.top();
            pq.pop();
            ans[k] = t.second;
            k--;
        }
        return ans;
    }
};

int main()
{
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;
    Solution s;
    vector<string> res = s.topKFrequent(words, k);
    for (auto &word : res)
    {
        cout << word << " ";
    }
    return 0;
}