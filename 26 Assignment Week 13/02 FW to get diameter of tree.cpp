class Solution
{
public:
    int D = 0;
    int getHeight(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        int cd = l + r;
        D = max(D, cd);
        return 1 + max(r, l);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        getHeight(root);
        return D;
    }
};