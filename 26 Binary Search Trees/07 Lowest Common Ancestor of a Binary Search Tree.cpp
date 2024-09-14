class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return NULL;

        if (p->val < root->val && q->val < root->val)
        {
            TreeNode *left = lowestCommonAncestor(root->left, p, q);
            if (left)
            {
                return left;
            }
        }
        if (p->val > root->val && q->val > root->val)
        {
            TreeNode *right = lowestCommonAncestor(root->right, p, q);
            if (right)
            {
                return right;
            }
        }
        return root;
    }
};