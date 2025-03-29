class Solution
{
public:
    bool isSafe(int row, int col, vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();

        return (row >= 0 && row < n && col >= 0 && col < m &&
                board[row][col] == 'O');
    }
    void solveDFS(int row, int col, vector<vector<char>> &board)
    {
        board[row][col] = '#';

        if (isSafe(row + 1, col, board))
        {
            solveDFS(row + 1, col, board);
        }
        if (isSafe(row - 1, col, board))
        {
            solveDFS(row - 1, col, board);
        }
        if (isSafe(row, col + 1, board))
        {
            solveDFS(row, col + 1, board);
        }
        if (isSafe(row, col - 1, board))
        {
            solveDFS(row, col - 1, board);
        }
    }
    void solve(vector<vector<char>> &board)
    {

        int row = board.size();
        int col = board[0].size();
        // Top Row
        for (int i = 0; i < col; i++)
        {
            if (board[0][i] == 'O')
            {
                solveDFS(0, i, board);
            }
        }
        // Right Column
        for (int i = 0; i < row; i++)
        {
            if (board[i][col - 1] == 'O')
            {
                solveDFS(i, col - 1, board);
            }
        }
        // bottom Row
        for (int i = 0; i < col; i++)
        {
            if (board[row - 1][i] == 'O')
            {
                solveDFS(row - 1, i, board);
            }
        }
        // left col
        for (int i = 0; i < row; i++)
        {
            if (board[i][0] == 'O')
            {
                solveDFS(i, 0, board);
            }
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};