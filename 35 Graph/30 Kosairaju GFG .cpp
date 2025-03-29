//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Position this line where user code will be pasted.
class Solution
{
public:
    void topo(int src, vector<bool> &vis, vector<vector<int>> &adj, stack<int> &st)
    {
        vis[src] = true;

        for (auto ch : adj[src])
        {
            if (!vis[ch])
            {
                topo(ch, vis, adj, st);
            }
        }
        st.push(src);
    }
    void dfs(int src, vector<bool> &vis, unordered_map<int, vector<int>> &newAdj)
    {
        vis[src] = false;

        for (auto ch : newAdj[src])
        {
            if (vis[ch])
            {
                dfs(ch, vis, newAdj);
            }
        }
    }
    int kosaraju(vector<vector<int>> &adj)
    {

        // topsort
        int n = adj.size();
        vector<bool> vis(n, false);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                topo(i, vis, adj, st);
            }
        }
        // transponse of graph

        unordered_map<int, vector<int>> newAdj;

        for (int i = 0; i < n; i++)
        {
            int src = i;
            for (auto ch : adj[i])
            {
                newAdj[ch].push_back(i);
            }
        }

        // pop back from stak dfs
        int c = 0;
        while (!st.empty())
        {
            int top = st.top();
            st.pop();
            if (vis[top])
            {
                c++;
                dfs(top, vis, newAdj);
            }
        }
        return c;
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
        cout << obj.kosaraju(adj) << "\n";

        // cout << "~"
        //      << "\n";
    }

    return 0;
}

// } Driver Code Ends