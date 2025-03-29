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

    void solveDFS2(int row, int col, vector<vector<int>> &board,
                   int &currArea)
    {
        board[row][col] = 0;
        currArea++;
        if (isSafe(row + 1, col, board))
        {
            solveDFS2(row + 1, col, board, currArea);
        }
        if (isSafe(row - 1, col, board))
        {
            solveDFS2(row - 1, col, board, currArea);
        }
        if (isSafe(row, col + 1, board))
        {
            solveDFS2(row, col + 1, board, currArea);
        }
        if (isSafe(row, col - 1, board))
        {
            solveDFS2(row, col - 1, board, currArea);
        }
    }
    int maxAreaOfIsland(vector<vector<int>> &board)
    {
        int row = board.size();
        int col = board[0].size();

        int maxArea = 0;
        int currArea = 0;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (board[i][j] == 1)
                {
                    solveDFS2(i, j, board, currArea);
                    maxArea = max(maxArea, currArea);
                    currArea = 0;
                }
            }
        }
        return maxArea;
    }
};