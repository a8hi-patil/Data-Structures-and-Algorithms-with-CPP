#include <iostream>
#include <cstdlib>
using namespace std;

int findMaxNumber(int arr[], int size)
{
    int res = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > res)
        {
            res = arr[i];
        }
    }

    return res;
}

int main()
{
    system("cls");
    int arr[] = {1, 6, 2, 4, 2, 4};
    cout << findMaxNumber(arr, 6) << endl;
    return 0;
}