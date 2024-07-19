#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
void storeSolution(vector<vector<char>> &board, vector<vector<string>> &ans, int n)
{
    vector<string> temp;
    for (int i = 0; i < n; i++)
    {
        string output = "";
        for (int j = 0; j < n; j++)
        {
            output.push_back(board[i][j]);
        }
        temp.push_back(output);
    }
    ans.push_back(temp);
}

unordered_map<int, bool> rowMap;
unordered_map<int, bool> upperDiagonalMap;
unordered_map<int, bool> lowerDiagonalMap;
bool isSafe(int row, int col, vector<vector<char>> &board)
{
    if (rowMap[row] == true || upperDiagonalMap[row - col] == true || lowerDiagonalMap[row + col] == true)
    {
        return false;
    }
    return true;
}

void solve(vector<vector<char>> &board, vector<vector<string>> &ans, int col, int n)
{
    // base case
    if (col >= n)
    {
        // store the solution
        storeSolution(board, ans, n);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board))
        {
            rowMap[row] = true;
            upperDiagonalMap[row - col] = true;
            lowerDiagonalMap[row + col] = true;
            board[row][col] = 'Q';
            solve(board, ans, col + 1, n);
            board[row][col] = '.';
            rowMap[row] = false;
            upperDiagonalMap[row - col] = false;
            lowerDiagonalMap[row + col] = false;
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<char>> board(n, vector<char>(n, '.'));
    vector<vector<string>> ans;
    int col = 0;
    solve(board, ans, col, n);
    return ans;
}
int main()
{
    system("cls");
    int n = 4;
    vector<vector<string>> ans = solveNQueens(n);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " , ";
        }
        cout << endl;
    }
    return 0;
}