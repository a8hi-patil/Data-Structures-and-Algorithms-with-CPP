//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool solve(int s, vector<bool> &vis2, vector<vector<int>> &adj,
               vector<bool> &vis)
    {

        vis[s] = true;
        vis2[s] = true;

        for (auto &ch : adj[s])
        {
            if (!vis[ch])
            {
                bool ans = solve(ch, vis2, adj, vis);
                if (ans)
                    return true;
            }
            else if (vis[ch] && vis2[ch])
            {
                return true;
            }
        }

        vis2[s] = false;
        return false;
    }
    a bool isCyclic(vector<vector<int>> &adj)
    {
        int numCourses = adj.size();
        vector<bool> vis(numCourses, false);
        vector<bool> vis2(numCourses, false);

        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i])
            {
                bool ans = solve(i, vis2, adj, vis);
                if (ans)
                {

                    return ans;
                }
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

// } Driver Code Ends