class Solution
{
public:
    int dfs(int src, unordered_map<int, vector<int>> &adj,
            vector<bool> &hasApple, vector<bool> &vis, int mycost)
    {
        if (vis[src])
            return 0;

        vis[src] = true;

        int sum = 0;

        for (auto el : adj[src])
        {
            sum += dfs(el, adj, hasApple, vis, 2);
        }
        if (sum == 0 && !hasApple[src])
            return 0;

        return sum + mycost;
    }
    int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
    {

        int y = edges.size();

        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < y; i++)
        {
            int src = edges[i][0];
            int des = edges[i][1];
            adj[src].push_back(des);
            adj[des].push_back(src);
        }

        vector<bool> vis(y + 1, false);
        int mycost = 0;
        int sum = 0;
        sum += dfs(0, adj, hasApple, vis, mycost);

        return (sum);
    }
};