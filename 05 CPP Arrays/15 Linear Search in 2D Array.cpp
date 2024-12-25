#include <iostream>
#include <cstdlib>
using namespace std;
bool linearSearchIn2DArray(int arr[][3], int row, int col, int target)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (target == arr[i][j])
                return true;
        }
    }
    return false;
}
int main()
{
    system("cls");
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int target = 8;
    bool res = linearSearchIn2DArray(arr, 3, 3, target);
    if (res)
    {
        cout << "Target Found" << endl;
    }
    else
    {
        cout << "Target Not Found" << endl;
    }
    return 0;
}