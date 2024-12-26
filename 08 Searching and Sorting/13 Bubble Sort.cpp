#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << " " << arr[i];

    cout << endl;
}
void bubbleSort(int arr[], int n)
{
    int counter = 1;

    while (counter < n)
    {
        for (int i = 0; i < n - counter; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
            }
        }
        counter++;
    }
}
int main()
{
    system("cls");
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int N = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, N);
    cout << "Sorted array: \n";
    printArray(arr, N);
    return 0;
}