class Solution
{
public:
    TreeNode *solve(vector<int> &arr, int &idx, int ub, int lb)
    {
        if (idx >= arr.size())
        {
            return NULL;
        }
        int el = arr[idx];
        TreeNode *root = nullptr;
        if (el > lb && el < ub)
        {
            root = new TreeNode(el);
            idx++;
            root->left = solve(arr, idx, el, lb);
            root->right = solve(arr, idx, ub, el);
        }
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int idx = 0;
        int ub = INT_MAX;
        int lb = INT_MIN;

        return solve(preorder, idx, ub, lb);
    }
};