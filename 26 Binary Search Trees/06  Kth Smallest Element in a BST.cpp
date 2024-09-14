
class Solution
{
public:
    void storeInorder(TreeNode *root, vector<int> &arr)
    {
        if (!root)
            return;

        storeInorder(root->left, arr);
        arr.push_back(root->val);
        storeInorder(root->right, arr);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        if (!root)
            return 0;

        vector<int> inorder;
        storeInorder(root, inorder);
        return inorder[k - 1];
    }
};