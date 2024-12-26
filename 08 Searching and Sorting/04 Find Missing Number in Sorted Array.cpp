#include <iostream>
#include <cstdlib>
using namespace std;

int missingNumber(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (arr[mid] == mid + 1)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return mid;
}

int main()
{
    system("cls");
    int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = 8;
    int missingNumIdx = missingNumber(arr, size);
    cout << "Missing number in array is " << missingNumIdx + 1 << endl;
    return 0;
}