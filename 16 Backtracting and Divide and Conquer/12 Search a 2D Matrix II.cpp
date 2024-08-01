#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
bool solve(vector<vector<int>> &matrix, int target, int row, int col)
{
    // cout << matrix[row][col] << endl;
    if (row > matrix[0].size() - 1 || col < 0)
    {
        return false;
    }
    if (matrix[row][col] == target)
    {
        return true;
    }
    if (matrix[row][col] > target)
    {
        return solve(matrix, target, row, col - 1);
    }
    if (matrix[row][col] < target)
    {
        return solve(matrix, target, row + 1, col);
    }
    return false;
}
int main()
{
    system("cls");
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15},
                                  {2, 5, 8, 12, 19},
                                  {3, 6, 9, 16, 22},
                                  {10, 13, 14, 17, 24},
                                  {18, 21, 23, 26, 30}};
    int m = matrix.size();
    int n = matrix[0].size();
    cout << solve(matrix, 5, 0, n - 1) << endl;
    return 0;
}