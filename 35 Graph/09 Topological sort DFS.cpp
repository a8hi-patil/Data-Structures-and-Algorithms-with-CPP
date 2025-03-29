class Solution
{
public:
    // Function to return list containing vertices in Topological order.

    void solve(int src, vector<vector<int>> &adj, unordered_map<int, bool> &vis, vector<int> &ans)
    {
        vis[src] = true;

        for (auto ch : adj[src])
        {
            if (!vis[ch])
            {
                solve(ch, adj, vis, ans);
            }
        }
        ans.push_back(src);
    }

    vector<int> topologicalSort(vector<vector<int>> &adj)
    {
        // Your code here
        unordered_map<int, bool> vis;
        vector<int> ans;

        for (int i = 0; i < adj.size(); i++)
        {
            if (!vis[i])
            {
                solve(i, adj, vis, ans);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
