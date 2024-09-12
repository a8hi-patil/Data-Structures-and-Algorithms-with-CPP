class Solution
{
    void solve(TreeNode *root, int &count)
    {
        if (!root)
            return;
        if (root->left)
        {
            count++;
            solve(root->left, count);
        }
        if (root->right)
        {
            count++;
            solve(root->right, count);
        }
    }

public:
    int countNodes(TreeNode *root)
    {
        int count = 0;
        if (!root)
            return count;
        count++;
        solve(root, count);
        return count;
    }
};