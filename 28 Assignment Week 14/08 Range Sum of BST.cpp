class Solution
{
public:
    void solve(TreeNode *root, int low, int high, int &sum)
    {
        if (!root)
            return;
        if (root->val >= low && root->val <= high)
        {
            sum += root->val;
            solve(root->left, low, high, sum);
            solve(root->right, low, high, sum);
        }

        if (root->val > high)
            solve(root->left, low, high, sum);

        if (root->val < low)
            solve(root->right, low, high, sum);
    }
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        int ans = 0;
        solve(root, low, high, ans);
        return ans;
    }
};