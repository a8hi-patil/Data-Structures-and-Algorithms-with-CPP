class Solution
{
public:
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int solve(Node *root)
    {
        if (!root)
            return 0;

        int lsum = solve(root->left);
        int rsum = solve(root->right);
        int val = root->data;
        root->data = lsum + rsum;
        return val + root->data;
    }
    void toSumTree(Node *node)
    {
        solve(node);
    }
};