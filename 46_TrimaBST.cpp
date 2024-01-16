#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        if (!root)
            return NULL;
        if (root->val < low)
        {
            return trimBST(root->right, low, high);
        }
        if (root->val > high)
        {
            return trimBST(root->left, low, high);
        }
        return new TreeNode(root->val, trimBST(root->left, low, high),
                            trimBST(root->right, low, high));
    }
};

int main()
{
    return 0;
}