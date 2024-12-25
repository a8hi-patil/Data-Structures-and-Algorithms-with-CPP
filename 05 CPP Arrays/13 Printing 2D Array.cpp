#include <iostream>
#include <cstdlib>
using namespace std;
void rowWisePrinting(int arr[][3], int row, int col)
{

    for (int i = 0; i < row; i++)
    {
        cout << "{";
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << ", ";
        }
        cout << "}";
        cout << endl;
    }
}
void columnWisePrinting(int arr[][3], int row, int col)
{

    for (int i = 0; i < row; i++)
    {
        cout << "{";
        for (int j = 0; j < col; j++)
        {
            cout << arr[j][i] << ", ";
        }
        cout << "}";
        cout << endl;
    }
}

void diagonalPrinting(int arr[][3], int row, int col)
{
    cout << "{";

    for (int j = 0; j < col; j++)
    {
        cout << arr[j][j] << ", ";
    }
    cout << "}";
}

void reverseDiagonalPrinting(int arr[][3], int row, int col)
{
    cout << "{";

    for (int j = 0; j < col; j++)
    {
        cout << arr[j][col - j - 1] << ", ";
    }
    cout << "}";
}
int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int row = 3;
    int col = 3;
    rowWisePrinting(arr, row, col);
    cout << endl;
    columnWisePrinting(arr, row, col);
    cout << endl;
    diagonalPrinting(arr, row, col);
    cout << endl;
    reverseDiagonalPrinting(arr, row, col);
    return 0;
}