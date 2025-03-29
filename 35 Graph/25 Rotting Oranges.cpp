class Solution
{
public:
    bool isSafe(int row, int col, vector<vector<int>> &board)
    {
        int n = board.size();
        int m = board[0].size();

        return (row >= 0 && row < n && col >= 0 && col < m &&
                board[row][col] == 1);
    }

    int orangesRotting(vector<vector<int>> &grid)
    {
        int min = 0;

        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }
        if (fresh == 0)
            return 0;
        while (!q.empty())
        {
            int size = q.size();
            int tmp = 0;
            while (size--)
            {
                auto front = q.front();
                q.pop();
                int x = front.first;
                int y = front.second;
                int ax[4] = {1, -1, 0, 0};
                int ay[4] = {0, 0, 1, -1};
                for (int i = 0; i < 4; i++)
                {
                    int x1 = x + ax[i];
                    int y1 = y + ay[i];
                    if (isSafe(x1, y1, grid))
                    {
                        tmp++;
                        grid[x1][y1] = 2;
                        q.push({x1, y1});
                    }
                }
            }
            if (tmp)
                min++;
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 1)
                {
                    min = 0;
                    break;
                }
            }
        }

        return min == 0 ? -1 : min;
    }
};