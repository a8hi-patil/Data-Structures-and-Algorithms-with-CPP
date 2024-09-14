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
class Info
{
public:
    int minVal;
    int maxVal;
    int sum;
    bool isBST;
};
class Solution
{
public:
    int calMin(int a, int b, int c)
    {
        int ans = min(a, min(b, c));
        return ans;
    }
    int calMax(int a, int b, int c)
    {
        int ans = max(a, max(b, c));
        return ans;
    }
    Info solve(TreeNode *root, int &sum)
    {
        if (root == NULL)
        {
            Info temp;
            temp.minVal = INT_MAX;
            temp.maxVal = INT_MIN;
            temp.sum = 0;
            temp.isBST = true;
            sum = max(temp.sum, sum);
            return temp;
        }
        if (root->left == NULL && root->right == NULL)
        {
            Info temp;
            temp.minVal = root->val;
            temp.maxVal = root->val;
            temp.sum = root->val;
            temp.isBST = true;
            sum = max(temp.sum, sum);
            return temp;
        }
        Info leftInfo = solve(root->left, sum);
        Info rightInfo = solve(root->right, sum);

        Info currentAns;
        currentAns.minVal = calMin(leftInfo.minVal, rightInfo.minVal, root->val);
        currentAns.maxVal = calMax(leftInfo.maxVal, rightInfo.maxVal, root->val);
        currentAns.sum = leftInfo.sum + rightInfo.sum + root->val;
        currentAns.isBST = (root->val > leftInfo.maxVal && root->val < rightInfo.minVal && leftInfo.isBST && rightInfo.isBST);

        if (currentAns.isBST)
        {
            sum = max(sum, currentAns.sum);
        }
        return currentAns;
    }
    int maxSumBST(TreeNode *root)
    {
        int sum = 0;
        solve(root, sum);
        return sum;
    }
};