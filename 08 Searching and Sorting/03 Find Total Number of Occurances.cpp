#include <iostream>
#include <cstdlib>
using namespace std;
int findFirstOccurance(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    int res = -1;
    while (start <= end)
    {
        if (target > arr[mid])
        {
            start = mid + 1;
        }
        else if (target < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            res = mid;
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return res;
}
int lastFirstOccurance(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    int res = -1;
    while (start <= end)
    {
        if (target > arr[mid])
        {
            start = mid + 1;
        }
        else if (target < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            res = mid;
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return res;
}
int main()
{
    system("cls");
    int arr[6] = {5, 7, 7, 8, 8, 10};
    int size = 6;
    int target = 8;
    cout << "Total Number of Occurances are " << lastFirstOccurance(arr, size, target) - findFirstOccurance(arr, size, target) + 1 << " !!" << endl;
    return 0;
}