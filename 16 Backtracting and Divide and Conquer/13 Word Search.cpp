#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
bool solve(vector<vector<char>> &board, string &word, int row, int col, int i)
{
    if (i == word.length())
    {
        return true;
    }
    if (row < 0 || row >= board.size() || col < 0 || col <= board[0].size() || board[row][col] != word[i])
    {
        return false;
    }
    char temp = board[row][col];
    board[row][col] = '%';
    bool found = solve(board, word, row + 1, col, i + 1) || solve(board, word, row - 1, col, i + 1) || solve(board, word, row, col + 1, i + 1) || solve(board, word, row, col - 1, i + 1);
    board[row][col] = temp;
    return found;
}
int main()
{
    system("cls");
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";

    int row = board.size();
    int col = board[0].size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (board[i][j] == word[0])
            {
                bool ans = solve(board, word, i, j, 0);
                if (ans)
                {
                    cout << "Found !!" << endl;
                    return;
                }
                else
                {
                    continue;
                }
            }
        }
    }
    return 0;
}