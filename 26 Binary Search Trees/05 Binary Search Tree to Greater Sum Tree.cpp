/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
    void calculateSum(vector<int> &arr)
    {
        int n = arr.size() - 2;
        while (n >= 0)
        {
            arr[n] = arr[n] + arr[n + 1];
            n--;
        }
    }
    void changeTree(TreeNode *root, vector<int> arr, int &idx)
    {
        if (!root)
            return;
        changeTree(root->left, arr, idx);
        root->val = arr[idx];
        idx++;
        changeTree(root->right, arr, idx);
    }
    TreeNode *bstToGst(TreeNode *root)
    {
        if (!root)
            return NULL;

        vector<int> inorder;
        storeInorder(root, inorder);
        calculateSum(inorder);
        int idx = 0;

        changeTree(root, inorder, idx);
        return root;
    }
};