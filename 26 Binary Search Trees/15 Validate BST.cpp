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
    bool validate(TreeNode *root, int lb, int ub)
    {
        if (!root)
            return true;
        bool isCurrentNodeInRange = root->val > lb && root->val < ub;

        bool lAns = validate(root->left, lb, root->val);
        bool rAns = validate(root->left, root->val, ub);
        return isCurrentNodeInRange && lAns && rAns;
    }
    bool isValidBST(TreeNode *root)
    {
        int ub = INT_MAX;
        int lb = INT_MIN;
        return validate(root, lb, ub);
    }
};