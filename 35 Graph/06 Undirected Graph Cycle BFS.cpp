class Solution
{
public:
    // Function to detect cycle in an undirected graph.

    bool isCyclePresent(int src, vector<vector<int>> &adj, unordered_map<int, bool> &vis)
    {
        queue<int> q;
        q.push(src);

        vis[src] = true;
        unordered_map<int, int> pMap;
        pMap[src] = -1;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (auto el : adj[front])
            {
                if (!vis[el])
                {
                    vis[el] = true;
                    pMap[el] = front;
                    q.push(el);
                }
                else if (vis[el] && pMap[front] != el)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(vector<vector<int>> &adj)
    {
        unordered_map<int, bool> vis;
        for (int i = 0; i < adj.size(); i++)
        {
            if (!vis[i] && isCyclePresent(i, adj, vis))
            {
                return true;
            }
        }
        return false;
    }
};
b