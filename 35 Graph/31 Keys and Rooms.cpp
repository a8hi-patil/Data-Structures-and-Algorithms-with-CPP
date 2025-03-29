class Solution
{
public:
    void topo(int src, vector<bool> &vis, vector<vector<int>> &adj)
    {
        vis[src] = true;

        for (auto ch : adj[src])
        {
            if (!vis[ch])
            {
                topo(ch, vis, adj);
            }
        }
    }

    bool dfs(vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<bool> vis(n, false);
        stack<int> st;

        topo(0, vis, adj);

        for (auto a : vis)
        {
            if (!a)
                return a;
        }
        return true;
    }
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        return dfs(rooms);
    }
};