class Solution
{
public:
    void solve(int n, unordered_map<int, vector<int>> &childs, int source,
               int destination, vector<bool> &vis)
    {
        vis[source] = true;
        queue<int> q;
        q.push(source);

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (auto nbr : childs[front])
            {
                if (!vis[nbr])
                {
                    vis[nbr] = true;
                    q.push(nbr);
                }
                if (vis[destination])
                    return;
            }
        }
    }
    bool validPath(int n, vector<vector<int>> &edges, int source,
                   int destination)
    {
        vector<bool> vis(n, false);
        unordered_map<int, vector<int>> childs;

        for (auto vr : edges)
        {
            childs[vr[0]].push_back(vr[1]);
            childs[vr[1]].push_back(vr[0]);
        }
        solve(n, childs, source, destination, vis);
        return vis[destination];
    }
};