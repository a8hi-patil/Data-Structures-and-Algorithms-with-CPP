#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
bool isSafe(vector<vector<char>> &board, char k, int row, int col)
{

    // row wise

    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == k)
            return false;
    }
    // cols wise
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == k)
            return false;
    }
    // check in 3*3 matrix

    for (int i = 0; i < 9; i++)
    {
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == k)
            return false;
    }
    return true;
}
bool solveSudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
            {

                for (int k = '1'; k <= '9'; k++)
                {
                    if (isSafe(board, k, i, j))
                    {

                        board[i][j] = k;

                        if (solveSudoku(board))
                        {
                            return true;
                        }
                        else
                        {
                            board[i][j] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    system("cls");
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    solveSudoku(board);
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            cout << board[i][j] << " ,";
        }
        cout << endl;
    }
    return 0;
}