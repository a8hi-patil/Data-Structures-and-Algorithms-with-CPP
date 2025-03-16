class Solution
{
public:
    void storeInOrder(TreeNode *root, vector<int> &inorder)
    {
        if (!root)
            return;
        storeInOrder(root->left, inorder);
        inorder.push_back(root->val);
        storeInOrder(root->right, inorder);
    }
    bool findAns(int target, vector<int> &inorder)
    {
        int start = 0;
        int end = inorder.size() - 1;
        while (start < end)
        {
            int ans = inorder[start] + inorder[end];
            if (ans == target)
            {
                return true;
            }
            else if (ans > target)
            {
                end--;
            }
            else
            {
                start++;
            }
        }
        return false;
    }
    bool findTarget(TreeNode *root, int k)
    {
        vector<int> inorder;
        storeInOrder(root, inorder);
        return findAns(k, inorder);
    }
};