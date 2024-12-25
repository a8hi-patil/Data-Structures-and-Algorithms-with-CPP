#include <iostream>
#include <cstdlib>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void transposeOfMatrix(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr[0].size(); j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
}
void reverseRow(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        reverse(arr[i].begin(), arr[i].end());
    }
}
int main()
{
    system("cls");
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    printMatrix(matrix);
    transposeOfMatrix(matrix);
    printMatrix(matrix);
    reverseRow(matrix);
    printMatrix(matrix);
}