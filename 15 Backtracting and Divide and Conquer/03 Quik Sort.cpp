#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
void quickSort(vector<int> &arr, int low, int high)
{
    // code here
    if (low >= high)
    {
        return;
    }

    int pivote = high;
    int i = low - 1;
    int j = low;

    while (j < pivote)
    {
        if (arr[j] < arr[pivote])
        {
            i++;
            swap(arr[j], arr[i]);
        }
        j++;
    }
    i++;
    swap(arr[i], arr[pivote]);
    quickSort(arr, low, i - 1);
    quickSort(arr, i + 1, high);
}
int main()
{
    system("cls");
    vector<int> arr = {3, 2, 4, 1, 5};
    int size = 5;
    int start = 0;
    int end = size - 1;

    cout << "Before Sorting" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    quickSort(arr, start, end);
    cout << "After Sorting" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}