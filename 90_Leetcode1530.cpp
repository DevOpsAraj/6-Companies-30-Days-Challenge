/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    int d;

    vector<int> getGoodLeafs(TreeNode *root, int &total)
    {
        if (!root)
            return {};
        vector<int> left = getGoodLeafs(root->left, total);
        vector<int> right = getGoodLeafs(root->right, total);
        if (left.size() == 0 && right.size() == 0)
            return {1};
        else if (left.size() == 0)
        {
            for (int i = 0; i < right.size(); i++)
                right[i]++;

            return right;
        }
        else if (right.size() == 0)
        {
            for (int i = 0; i < left.size(); i++)
                left[i]++;

            return left;
        }
        else
        {
            sort(left.begin(), left.end());
            sort(right.begin(), right.end());

            int i = 0, j;
            while (i < left.size())
            {
                j = 0;
                while (j < right.size() && left[i] + right[j] <= d)
                {
                    total++;
                    j++;
                }
                i++;
            }

            left.reserve(left.size() + right.size());
            left.insert(left.end(), right.begin(), right.end());

            for (int i = 0; i < left.size(); i++)
                left[i]++;

            return left;
        }
    }

    int countPairs(TreeNode *root, int distance)
    {
        d = distance;
        int total = 0;
        getGoodLeafs(root, total);
        return total;
    }
};