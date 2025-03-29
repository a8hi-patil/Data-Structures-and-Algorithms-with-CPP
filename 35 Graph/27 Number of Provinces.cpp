class Solution
{
public:
    void dfs(int src, vector<vector<int>> &adj, vector<bool> &vis)
    {
        vis[src] = true;

        for (int i = 0; i < adj.size(); i++)
        {
            if (adj[src][i] == 1 && !vis[i])
            {
                dfs(i, adj, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        int ans = 0;
        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                ans++;
                dfs(i, isConnected, vis);
            }
        }
        return ans;
    }
};