class Solution
{
public:
    unordered_map<int, vector<int>> adj;
    int ans = 0;
    int maxi = 0;

    void dfs(int head, vector<int> &informTime)
    {
        maxi = max(ans, maxi);

        for (auto nbr : adj[head])
        {
            ans += informTime[head];
            dfs(nbr, informTime);
            ans -= informTime[head];
        }
    }
    int numOfMinutes(int n, int headID, vector<int> &manager,
                     vector<int> &informTime)
    {

        for (int i = 0; i < n; i++)
        {
            if (manager[i] != -1)
            {
                adj[manager[i]].push_back(i);
            }
        }
        dfs(headID, informTime);
        return maxi;
    }
};