class Solution
{
public:
    int stoneGameVI(vector<int> &aliceValues, vector<int> &bobValues)
    {
        int n = aliceValues.size(), diff = 0;
        for (int i = 0; i < n; i++)
        {
            aliceValues[i] += bobValues[i];
            diff -= bobValues[i];
        }
        sort(begin(aliceValues), end(aliceValues));
        for (int i = n - 1; i >= 0; i -= 2)
            diff += aliceValues[i];
        return diff == 0 ? 0 : diff > 0 ? 1
                                        : -1;
    }
};