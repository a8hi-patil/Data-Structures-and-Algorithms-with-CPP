/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int solve(TreeNode *root, int &count)
    {
        if (!root)
            return 1;
        int l = solve(root->left, count);
        int r = solve(root->right, count);

        if (l == 0 || r == 0)
        {
            count++;
            return 2;
        }
        if (l == 2 || r == 2)
        {
            return 1;
        }
        return 0;
    }
    int minCameraCover(TreeNode *root)
    {
        int cameras = 0;
        int rootState = solve(root, cameras);
        if (rootState == 0)
        {
            cameras++;
        }
        return cameras;
    }
};