#include <iostream>
#include <cstdlib>
using namespace std;
int binarySearch(int arr[], int size, int target)
{

    int end = size - 1;
    int start = 0;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (target > arr[mid])
        {
            start = mid + 1;
        }
        else if (target < arr[mid])
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}
int main()
{
    system("cls");
    int arr[5] = {1, 2, 3, 4, 5};
    int size = 5;
    int target = 4;
    int targetIdx = binarySearch(arr, size, target);
    if (targetIdx == -1)
    {
        cout << "Target not found !!" << endl;
    }
    else
    {
        cout << "Target found at index " << targetIdx << " !!" << endl;
    }
    int target1 = 24;
    int targetIdx1 = binarySearch(arr, size, target1);
    if (targetIdx1 == -1)
    {
        cout << "Target not found !!" << endl;
    }
    else
    {
        cout << "Target found at index " << targetIdx1 << " !!" << endl;
    }
}