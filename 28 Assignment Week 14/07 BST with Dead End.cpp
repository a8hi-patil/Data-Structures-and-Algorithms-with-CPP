class Solution
{
public:
    void solve(Node *root, unordered_map<int, bool> &vis, bool &ans)
    {
        if (!root)
            return;
        vis[root->data] = true;
        int xp1 = root->data + 1;
        int xm1 = root->data - 1 == 0 ? root->data : root->data - 1;
        if (vis.find(xp1) != vis.end() && vis.find(xm1) != vis.end())
        {
            ans = true;
            return;
        }
        solve(root->left, vis, ans);
        solve(root->right, vis, ans);
    }

    bool isDeadEnd(Node *root)
    {
        bool ans = false;
        unordered_map<int, bool> vis;
        solve(root, vis, ans);
        return ans;
    }
};