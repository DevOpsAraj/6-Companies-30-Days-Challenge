class Solution
{
public:
    vector<vector<int>> outerTrees(vector<vector<int>> &trees)
    {
        vector<vector<int>> res;
        vector<vector<int>> treeGraph(101);
        for (auto &tree : trees)
        {
            treeGraph[tree[0]].push_back(tree[1]);
        }

        int firstX = -1;
        for (int i = 0; i < 101; i++)
        {
            std::sort(treeGraph[i].begin(), treeGraph[i].end());
            if (firstX == -1 && treeGraph[i].size())
            {
                firstX = i;
                for (auto &tt : treeGraph[i])
                {
                    res.push_back({i, tt});
                }
            }
        }
        for (int i = 100; i >= 0; --i)
        {
            if (treeGraph[i].size())
            {
                for (auto &tt : treeGraph[i])
                {
                    res.push_back({i, tt});
                }
                break;
            }
        }
        int index = firstX;
        while (index < 101)
        {
            vector<vector<int>> tmpRes;
            vector<int> dis = {1, -101};
            for (int i = index + 1; i < 101; i++)
            {
                if (treeGraph[i].size() == 0)
                {
                    continue;
                }
                vector<int> tmpdis = {
                    i - index,
                    treeGraph[i][treeGraph[i].size() - 1] -
                        treeGraph[index][treeGraph[index].size() - 1]};
                if (dis[1] * tmpdis[0] < dis[0] * tmpdis[1])
                {
                    tmpRes.clear();
                }
                if (dis[1] * tmpdis[0] <= dis[0] * tmpdis[1])
                {
                    tmpRes.push_back(
                        {index + tmpdis[0],
                         treeGraph[index][treeGraph[index].size() - 1] +
                             tmpdis[1]});
                    dis.swap(tmpdis);
                }
            }
            if (tmpRes.size())
            {
                index = tmpRes[tmpRes.size() - 1][0];
                for (auto &tt : tmpRes)
                {
                    res.push_back(std::move(tt));
                }
            }
            else
            {
                break;
            }
        }
        index = firstX;
        while (index < 101)
        {
            vector<vector<int>> tmpRes;
            vector<int> dis = {1, 101};
            for (int i = index + 1; i < 101; i++)
            {
                if (treeGraph[i].size() == 0)
                {
                    continue;
                }

                vector<int> tmpdis = {i - index,
                                      treeGraph[i][0] - treeGraph[index][0]};

                if (dis[1] * tmpdis[0] > dis[0] * tmpdis[1])
                {
                    tmpRes.clear();
                }
                if (dis[1] * tmpdis[0] >= dis[0] * tmpdis[1])
                {
                    tmpRes.push_back(
                        {index + tmpdis[0], treeGraph[index][0] + tmpdis[1]});
                    dis.swap(tmpdis);
                }
            }
            if (tmpRes.size())
            {
                index = tmpRes[tmpRes.size() - 1][0];
                for (auto &tt : tmpRes)
                {
                    res.push_back(std::move(tt));
                }
            }
            else
            {
                break;
            }
        }
        std::sort(res.begin(), res.end());
        vector<int> dummy(2, -1);
        for (auto iter = res.begin(); iter != res.end();)
        {

            auto &v = *iter;
            if (v[0] == dummy[0] && v[1] == dummy[1])
            {
                iter = res.erase(iter);
            }
            else
            {
                dummy = *iter;
                ++iter;
            }
        }

        return res;
    }
};