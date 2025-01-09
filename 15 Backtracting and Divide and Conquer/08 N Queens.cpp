#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, bool> rowMap;
unordered_map<int, bool> UDMap;
unordered_map<int, bool> LDMap;

void storeAns(vector<vector<char>> &board, vector<vector<string>> &ans)
{

    string ansS = "";
    vector<string> temp;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            ansS += board[i][j];
        }
        temp.push_back(ansS);
        ansS = "";
    }
    ans.push_back(temp);
}

bool isLocationSafe(int row, int col)
{

    if (rowMap[row] || UDMap[row - col] || LDMap[row + col])
        return false;
    return true;
}
void solve(int n, vector<vector<string>> &ans, vector<vector<char>> &board, int col)
{
    if (col >= n)
    {
        storeAns(board, ans);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isLocationSafe(i, col))
        {
            rowMap[i] = true;
            UDMap[i - col] = true;
            LDMap[i + col] = true;
            board[i][col] = 'Q';
            solve(n, ans, board, col + 1);
            board[i][col] = '.';
            rowMap[i] = false;
            UDMap[i - col] = false;
            LDMap[i + col] = false;
        }
    }
}

void solveNQueens(int n, vector<vector<string>> &ans)
{
    vector<vector<char>> board(n, vector<char>(n, '.'));
    int col = 0;
    solve(n, ans, board, col);
}
int main()
{
    system("cls");
    int n = 4;
    vector<vector<string>> ans;
    solveNQueens(n, ans);

    for (auto a : ans)
    {
        for (auto b : a)
        {

            cout << b << endl;
        }
        cout << endl;
    }

    return 0;
}