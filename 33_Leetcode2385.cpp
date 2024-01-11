#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // to store maximum distance from the start node.
    int maxDistance = 0;

public:
    int amountOfTime(TreeNode *root, int start)
    {
        traverse(root, start);
        return maxDistance;
    }

    // Function to perform DFS
    int traverse(TreeNode *root, int start)
    {
        int depth = 0;
        // If root is null, return 0.
        if (root == nullptr)
        {
            return depth;
        }

        // Recursively call traverse with root.left and save in the variable
        // leftDepth.
        int leftDepth = traverse(root->left, start);
        // Recursively call traverse with root.right and save in the variable
        // rightDepth.
        int rightDepth = traverse(root->right, start);

        // the root is the start node
        if (root->val == start)
        {
            // Calculate the start node's max depth.
            maxDistance = max(leftDepth, rightDepth);
            // signify this is the start node.
            depth = -1;
        }
        else if (leftDepth >= 0 && rightDepth >= 0)
        {
            // calculate the current root's max depth.
            depth = max(leftDepth, rightDepth) + 1;
        }
        // current root's subtree contains the start node
        else
        {
            // distance of the furthest node in the other subtree.
            int distance = abs(leftDepth) + abs(rightDepth);
            maxDistance = max(maxDistance, distance);
            // calculate a negative number that signifies the subtree contains
            // the start node and represents the distance of the start node from
            // the root.
            depth = min(leftDepth, rightDepth) - 1;
        }

        return depth;
    }
};