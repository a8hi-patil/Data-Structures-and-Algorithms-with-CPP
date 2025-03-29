//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to detect cycle in an undirected graph.

    bool solve(int src, vector<vector<int>> &adj, unordered_map<int, bool> &vis, int parent)
    {

        vis[src] = true;

        bool ans = false;
        for (auto child : adj[src])
        {
            if (!vis[child])
            {
                ans = solve(child, adj, vis, src);
                if (ans)
                    return true;
            }
            else if (vis[child] == true && child != parent)
            {
                return true;
            }
        }
        return ans;
    }
    bool isCycle(vector<vector<int>> &adj)
    {
        // Code here
        // handle disconnected components
        int n = adj.size();
        unordered_map<int, bool> vis;
        int parent = -1;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i] && solve(i, adj, vis, parent))
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
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends