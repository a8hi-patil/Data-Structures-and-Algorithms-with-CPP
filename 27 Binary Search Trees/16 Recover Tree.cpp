class Solution
{
    TreeNode *one = nullptr;
    TreeNode *two = nullptr;
    TreeNode *prev = nullptr;

public:
    void inOrder(TreeNode *curr)
    {
        if (!curr)
            return;

        inOrder(curr->left);

        if (prev && prev->val > curr->val)
        {
            if (!one)
                one = prev;
            two = curr;
        }
        prev = curr;
        inOrder(curr->right);
    }
    void recoverTree(TreeNode *root)
    {
        inOrder(root);
        if (one && two)
            swap(one->val, two->val);
    }
};