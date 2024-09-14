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
    void solve(TreeNode *root, TreeNode *&prev, int &minDiff)
    {
        if (root == NULL)
            return;
        solve(root->left, prev, minDiff);

        if (prev)
        {
            minDiff = min(abs(root->val - prev->val), minDiff);
        }
        prev = root;
        solve(root->right, prev, minDiff);
    }
    int minDiffInBST(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int minDiff = INT_MAX;
        TreeNode *prev = NULL;
        solve(root, prev, minDiff);
        return minDiff;
    }
};