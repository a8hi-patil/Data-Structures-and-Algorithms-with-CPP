#include <iostream>
#include <cstdlib>
using namespace std;
void merge(int arr[], int s, int e)
{
    int m = s + (e - s) / 2;
    int leftArrayLen = m - s + 1;
    int rightArrayLen = e - m;
    int *leftNewArray = new int[leftArrayLen];
    int *rightNewArray = new int[rightArrayLen];

    // Filling arrays
    int idx = s;
    for (int i = 0; i < leftArrayLen; i++)
    {
        leftNewArray[i] = arr[idx++];
    }
    for (int i = 0; i < rightArrayLen; i++)
    {
        rightNewArray[i] = arr[idx++];
    }
    // merge two sorted arrays

    int i = 0, j = 0;
    int mainArrayIndex = s;
    while (i < leftArrayLen && j < rightArrayLen)
    {
        if (leftNewArray[i] < rightNewArray[j])
        {
            arr[mainArrayIndex++] = leftNewArray[i++];
        }
        else
        {
            arr[mainArrayIndex++] = rightNewArray[j++];
        }
    }
    while (i < leftArrayLen)
    {
        arr[mainArrayIndex++] = leftNewArray[i++];
    }
    while (j < rightArrayLen)
    {
        arr[mainArrayIndex++] = rightNewArray[j++];
    }

    delete[] leftNewArray;
    delete[] rightNewArray;
}

void mergSort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int m = s + (e - s) / 2;
    mergSort(arr, s, m);
    mergSort(arr, m + 1, e);
    merge(arr, s, e);
}
int main()
{
    system("cls");
    int arr[5] = {3, 2, 4, 1, 5};
    int size = 5;
    int start = 0;
    int end = size - 1;

    cout << "Before Sorting" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    mergSort(arr, start, end);
    cout << "After Sorting" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}