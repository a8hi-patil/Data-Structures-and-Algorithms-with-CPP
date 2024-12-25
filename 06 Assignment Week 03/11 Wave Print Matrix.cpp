#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void wavePrint(vector<vector<int>> &arr)
{
    int m = arr.size();
    int n = arr[0].size();

    for (int i = 0; i < n; i++)
    {

        if (i % 2)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                cout << arr[j][i] << ",";
            }
        }
        else
        {
            for (int j = 0; j < m; j++)
            {
                cout << arr[j][i] << ",";
            }
        }
        cout << endl;
    }
}

int main()
{
    system("cls");

    vector<vector<int>> nums = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    wavePrint(nums);

    return 0;
}