#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

void print2DArray(vector<vector<int>> &arr)
{

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            cout << arr[i][j] << " ,";
        }
        cout << endl;
    }
}
void transposeOfMatrix(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    print2DArray(arr);
    transposeOfMatrix(arr);
    print2DArray(arr);
    return 0;
}