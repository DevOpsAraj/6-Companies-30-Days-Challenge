#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int charToIntAtPosition(string &str, int position)
    {
        return str[str.size() - position] - '0';
    }
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        int numStrings = nums.size();
        int stringLength = nums[0].size();
        vector<vector<int>> indexSortedByRadix(stringLength + 1, vector<int>(numStrings, 0));

        iota(indexSortedByRadix[0].begin(), indexSortedByRadix[0].end(), 0);

        for (int radix = 1; radix <= stringLength; radix++)
        {
            vector<int> countDigits(10, 0);
            for (int i = 0; i < numStrings; i++)
                ++countDigits[charToIntAtPosition(nums[i], radix)];
            int index = 0;
            for (int &count : countDigits)
            {
                int temp = count;
                count = index;
                index += temp;
            }
            vector<int> newSortedIndex(numStrings, 0);
            for (int i = 0; i < numStrings; i++)
            {
                int prevIndex = indexSortedByRadix[radix - 1][i];
                int digit = charToIntAtPosition(nums[prevIndex], radix);
                newSortedIndex[countDigits[digit]] = prevIndex;
                countDigits[digit]++;
            }
            indexSortedByRadix[radix] = newSortedIndex;
        }
        vector<int> results(queries.size());
        for (int i = 0; i < queries.size(); ++i)
        {
            int k = queries[i][0];
            int radix = queries[i][1];
            results[i] = indexSortedByRadix[radix][k - 1];
        }
        return results;
    }
};
int main()
{
    vector<string> nums = {"102", "473", "251", "814"};
    vector<vector<int>> queries = {{1, 1}, {2, 3}, {4, 2}, {1, 2}};
    Solution s;
    vector<int> result = s.smallestTrimmedNumbers(nums, queries);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}