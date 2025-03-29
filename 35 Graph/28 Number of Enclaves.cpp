
class Solution
{
public:
    bool isSafe(int i, int j, vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        return (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1);
    }
    void dfs(int i, int j, vector<vector<int>> &grid)
    {
        grid[i][j] = 0;

        int ax[4] = {0, 0, 1, -1};
        int ay[4] = {1, -1, 0, 0};
        for (int k = 0; k < 4; k++)
        {
            if (isSafe(i + ax[k], j + ay[k], grid))
            {
                dfs(i + ax[k], j + ay[k], grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // top row = 0 col -> m

        for (int i = 0; i < m; i++)
        {
            if (grid[0][i] == 1)
            {
                dfs(0, i, grid);
            }
        }
        // bottom row = n-1 col -> m

        for (int i = 0; i < m; i++)
        {
            if (grid[n - 1][i] == 1)
            {
                dfs(n - 1, i, grid);
            }
        }
        // right col row->n col = m-1

        for (int i = 0; i < n; i++)
        {
            if (grid[i][m - 1] == 1)
            {
                dfs(i, m - 1, grid);
            }
        }
        // left col row->n col = 0

        for (int i = 0; i < n; i++)
        {
            if (grid[i][0] == 1)
            {
                dfs(i, 0, grid);
            }
        }
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    c++;
            }
        }
        return c;
    }
};