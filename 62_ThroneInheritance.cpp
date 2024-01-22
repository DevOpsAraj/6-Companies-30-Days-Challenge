#include <bits/stdc++.h>
using namespace std;

static const int ZERO = []()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    return 0;
}();

class ThroneInheritance
{
public:
    unordered_set<string> dead;
    unordered_map<string, vector<string>> children;
    string king;

    ThroneInheritance(string kingName) { king = kingName; }

    void birth(string parentName, string childName)
    {
        children[parentName].push_back(childName);
    }

    void death(string name) { dead.insert(name); }

    vector<string> getInheritanceOrder()
    {
        vector<string> currOrder;
        dfs(king, currOrder);
        return currOrder;
    }

    void dfs(string name, vector<string> &order)
    {
        if (dead.count(name) == 0)
        {
            order.push_back(name);
        }

        for (auto &child : children[name])
        {
            dfs(child, order);
        }
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */