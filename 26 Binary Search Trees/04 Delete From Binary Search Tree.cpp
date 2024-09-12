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
        if (root == NULL)
        {
            return NULL;
        }
        if (root->val == key)
        {
            // case 1 leaf node
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            // case 2 leaft node
            if (root->left != NULL && root->right == NULL)
            {
                TreeNode *leftChild = root->left;
                root->left = NULL;
                delete root;
                return leftChild;
            }
            // case 3 right node
            if (root->left == NULL && root->right != NULL)
            {
                TreeNode *rightChild = root->right;
                root->right = NULL;
                delete root;
                return rightChild;
            }
            // case 4 both node
            if (root->left != NULL && root->right != NULL)
            {
                int maxVal = getMax(root->left);
                root->val = maxVal;
                root->left = deleteNode(root->left, maxVal);
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