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
    void solve(TreeNode *root, int k, int &c, TreeNode *&ans)
    {
        if (!root)
            return;
        solve(root->left, k, c, ans);
        c++;
        if (c == k)
        {
            ans = root;
        }
        if (ans)
            return;
        solve(root->right, k, c, ans);
    }

    int kthSmallest(TreeNode *root, int k)
    {

        if (!root)
            return -1;
        TreeNode *ans = nullptr;
        int c = 0;
        solve(root, k, c, ans);
        if (!ans)
            return -1;
        return ans->val;
    }
};