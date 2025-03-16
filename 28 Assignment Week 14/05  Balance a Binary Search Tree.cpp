class Solution
{
public:
    void inorder(TreeNode *root, vector<int> &in)
    {
        if (!root)
            return;
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }
    TreeNode *buildBST(vector<int> &in, int s, int e)
    {
        if (s > e)
            return nullptr;
        int m = s + (e - s) / 2;
        TreeNode *root = new TreeNode(in[m]);
        root->left = buildBST(in, s, m - 1);
        root->right = buildBST(in, m + 1, e);
        return root;
    }
    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> in;
        inorder(root, in);
        int s = 0;
        int e = in.size() - 1;

        return buildBST(in, s, e);
    }
};