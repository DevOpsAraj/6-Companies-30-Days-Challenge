#include <bits/stdc++.h>
using namespace std;

const static auto fast = []
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution
{

public:
    struct Info
    {
        int maxSum;   // Maximum sub-tree sum
        int totalSum; // Total sum of the sub-tree
        int minVal;   // Minimum value in the sub-tree
        int maxVal;   // Maximum value in the sub-tree
        bool isBST;   // Whether the sub-tree is a BST

        Info(int maxSum, int totalSum, int minVal, int maxVal, bool isBST)
            : maxSum(maxSum), totalSum(totalSum), minVal(minVal),
              maxVal(maxVal), isBST(isBST) {}
    };

    Info findMaxBSTSubTreeSum(TreeNode *root, int &maxSum)
    {
        if (root == nullptr)
        {
            return {0, 0, INT_MAX, INT_MIN, true};
        }

        // Recursively calculate information for left and right subtrees
        Info leftInfo = findMaxBSTSubTreeSum(root->left, maxSum);
        Info rightInfo = findMaxBSTSubTreeSum(root->right, maxSum);

        // Check if the current subtree is a valid BST
        if (leftInfo.isBST && rightInfo.isBST && root->val > leftInfo.maxVal &&
            root->val < rightInfo.minVal)
        {
            int totalSum = root->val + leftInfo.totalSum + rightInfo.totalSum;
            int currentMaxSum =
                max({leftInfo.maxSum, rightInfo.maxSum, totalSum});
            maxSum = max(maxSum, currentMaxSum);

            return {currentMaxSum, totalSum, min(root->val, leftInfo.minVal),
                    max(root->val, rightInfo.maxVal), true};
        }
        else
        {
            // If the current subtree is not a valid BST, mark it as such
            return {max(leftInfo.maxSum, rightInfo.maxSum), 0, 0, 0, false};
        }
    }

    int maxSumBST(TreeNode *root)
    {
        int maxSum = INT_MIN;
        findMaxBSTSubTreeSum(root, maxSum);
        return maxSum;
    }
};

// Construct Tree

int main()
{
    // --------

    return 0;
}