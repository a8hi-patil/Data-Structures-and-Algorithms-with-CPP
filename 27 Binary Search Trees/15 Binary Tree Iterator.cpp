class BSTIterator
{
    stack<TreeNode *> st;

    void storeLeftNode(TreeNode *root)
    {
        TreeNode *temp = root;
        while (temp)
        {
            st.push(temp);
            temp = temp->left;
        }
    }

public:
    BSTIterator(TreeNode *root) { storeLeftNode(root); }

    int next()
    {
        TreeNode *top = st.top();
        st.pop();
        if (top->right)
            storeLeftNode(top->right);
        return top->val;
    }

    bool hasNext() { return !st.empty(); }
};
b