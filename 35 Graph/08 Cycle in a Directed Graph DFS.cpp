class Solution
{
public:
    // Function to detect cycle in a directed graph.

    bool solve(int parent, vector<vector<int>> &adj, unordered_map<int, bool> &vis, unordered_map<int, bool> &path)
    {
        vis[parent] = true;
        path[parent] = true;

        for (auto chld : adj[parent])
        {
            if (!vis[chld])
            {
                bool ans = solve(chld, adj, vis, path);
                if (ans)
                    return ans;
            }
            else if (vis[chld] && path[chld])
            {
                return true;
            }
        }
        path[parent] = false;
        return false;
    }
    bool isCyclic(vector<vector<int>> &adj)
    {
        // code here

        int n = adj.size();
        unordered_map<int, bool> vis;
        unordered_map<int, bool> path;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i] && solve(i, adj, vis, path))
            {
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
