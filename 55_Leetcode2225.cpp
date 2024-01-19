class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int present[100001] = {0};
        int losses[100001] = {0};
        vector<vector<int>> res(2);

        for (auto& it : matches) {
            int winner = it[0], loser = it[1];
            present[winner] = 1;
            present[loser] = 1;

            losses[loser]++;
        }

        for (int i = 1; i < 100001; i++) {
            if (!present[i])
                continue;

            if (losses[i] == 0)
                res[0].push_back(i);
            else if (losses[i] == 1)
                res[1].push_back(i);
        }
        return res;
    }
};