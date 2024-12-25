#include <iostream>
#include <cstdlib>
using namespace std;

int findUnique(int arr[], int size)
{
    int ans = 0;

    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }

    return ans;
}

int main()
{
    system("cls");
    int arr[] = {1, 2, 1, 2, 3};

    cout << findUnique(arr, 5);
    return 0;
}