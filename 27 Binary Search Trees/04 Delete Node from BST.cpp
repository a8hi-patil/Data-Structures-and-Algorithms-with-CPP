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
    int getMax(TreeNode *root)
    {
        if (!root)
            return -1;
        while (root->right)
            root = root->right;
        return root->val;
    }
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return NULL;
        if (root->val == key)
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            if (root->left != NULL && root->right == NULL)
            {
                TreeNode *leftChild = root->left;
                delete root;
                return leftChild;
            }
            if (root->left == NULL && root->right != NULL)
            {
                TreeNode *rightChild = root->right;
                delete root;
                return rightChild;
            }
            if (root->left != NULL && root->right != NULL)
            {

                int maxEle = getMax(root->left);
                root->val = maxEle;
                root->left = deleteNode(root->left, maxEle);
                return root;
            }
        }
        else
        {
            if (key < root->val)
            {
                root->left = deleteNode(root->left, key);
            }
            else
            {
                root->right = deleteNode(root->right, key);
            }
        }
        return root;
    }
};