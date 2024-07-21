#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
bool isSafe(int row, int col, char digit, vector<vector<char>> &board)
{
    int n = board.size();
    // checking row wise

    for (int i = 0; i < n; i++)
    {
        if (board[row][i] == digit)
            return false;
    }

    // checking column wise
    for (int i = 0; i < n; i++)
    {
        if (board[i][col] == digit)
            return false;
    }
    // checking 3*3 matrix wise
    for (int i = 0; i < n; i++)
    {
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == digit)
            return false;
    }
    return true;
}
bool solveSudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == '.')
            {

                for (char digit = '1'; digit <= '9'; digit++)
                {
                    if (isSafe(i, j, digit, board))
                    {
                        board[i][j] = digit;
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