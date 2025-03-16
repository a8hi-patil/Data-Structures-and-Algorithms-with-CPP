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
    void storeInorder(TreeNode *root, vector<int> &inorder)
    {
        if (!root)
        {
            return;
        }
        storeInorder(root->left, inorder);
        inorder.push_back(root->val);
        storeInorder(root->right, inorder);
    }
    void calculateAns(vector<int> &inorder)
    {
        for (int i = inorder.size() - 2; i >= 0; i--)
        {
            inorder[i] = inorder[i] + inorder[i + 1];
        }
    }
    void updateTree(TreeNode *root, vector<int> &inorder, int &idx)
    {
        if (!root)
            return;
        if (idx >= inorder.size())
            return;
        updateTree(root->left, inorder, idx);
        root->val = inorder[idx++];
        updateTree(root->right, inorder, idx);
    }
    TreeNode *convertBST(TreeNode *root)
    {
        if (!root)
            return nullptr;
        if (!root->left && !root->right)
        {
            return root;
        }
        vector<int> inorder;
        storeInorder(root, inorder);
        calculateAns(inorder);
        int idx = 0;
        updateTree(root, inorder, idx);
        return root;
    }
};