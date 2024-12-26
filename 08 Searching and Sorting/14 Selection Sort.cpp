#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <limits>
using namespace std;
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int findMinIdx(int arr[], int s, int end)
{
    int val = INT_MAX;
    int idx = -1;

    for (int i = s; i <= end; i++)
    {
        if (arr[i] < val)
        {
            val = arr[i];
            idx = i;
        }
    }
    return idx;
}

void selectionSort(int arr[], int n)
{
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        swap(arr[findMinIdx(arr, start, end)], arr[start++]);
    }
}

int main()
{
    system("cls");
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function Call
    selectionSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}