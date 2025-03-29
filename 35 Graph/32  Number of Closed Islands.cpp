class Solution
{
public:
    bool isSafe(int i, int j, vector<vector<int>> &grid, int x)
    {
        int n = grid.size();
        int m = grid[0].size();
        return (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 0);
    }
    void dfs(int i, int j, vector<vector<int>> &grid, int x)
    {
        grid[i][j] = x;

        int ax[4] = {0, 0, 1, -1};
        int ay[4] = {-1, 1, 0, 0};

        for (int k = 0; k < 4; k++)
        {
            if (isSafe(i + ax[k], j + ay[k], grid, x))
            {
                dfs(i + ax[k], j + ay[k], grid, x);
            }
        }
    }
    int closedIsland(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i * j == 0 || i == n - 1 || j == m - 1) && grid[i][j] == 0)
                {
                    dfs(i, j, grid, 1);
                }
            }
        }
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    c++;
                    dfs(i, j, grid, 1);
                }
            }
        }
        return c;
    }
};