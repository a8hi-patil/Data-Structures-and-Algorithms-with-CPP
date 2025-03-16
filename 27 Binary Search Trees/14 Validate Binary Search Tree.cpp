class Solution
{
public:
    bool solve(TreeNode *root, long long ub, long long lb)
    {
        if (!root)
            return 1;
        bool check = root->val < ub && root->val > lb;
        if (!check)
            return false;
        return check && solve(root->left, root->val, lb) &&
               solve(root->right, ub, root->val);
    }
    bool isValidBST(TreeNode *root)
    {
        long long lb = LONG_MIN;
        long long ub = LONG_MAX;
        return solve(root, ub, lb);
    }
};