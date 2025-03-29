class Solution
{
public:
    void solve(vector<vector<int>> &graph, int src, int des,
               vector<vector<int>> &ans, vector<int> temp)
    {

        temp.push_back(src);
        if (src == des)
        {
            ans.push_back(temp);
        }
        else
        {
            for (auto &ch : graph[src])
            {
                solve(graph, ch, des, ans, temp);
            }
        }

        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {

        int src = 0;
        int des = graph.size() - 1;

        vector<vector<int>> ans;
        vector<int> temp;
        solve(graph, src, des, ans, temp);
        return ans;
    }
};