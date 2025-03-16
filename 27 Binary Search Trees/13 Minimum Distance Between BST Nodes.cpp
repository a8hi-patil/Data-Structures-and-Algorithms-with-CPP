class Solution
{
public:
    void solve(TreeNode *root, TreeNode *&prev, int &ans)
    {
        if (!root)
            return;
        solve(root->left, prev, ans);
        if (prev)
            ans = min(ans, root->val - prev->val);
        prev = root;
        solve(root->right, prev, ans);
    }
    int minDiffInBST(TreeNode *root)
    {
        int ans = INT_MAX;
        TreeNode *prev = nullptr;
        solve(root, prev, ans);
        return ans;
    }
};