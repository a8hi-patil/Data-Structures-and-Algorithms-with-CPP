#include <iostream>
#include <limits>
#include <cstdlib>
using namespace std;
int findPeakIndexInMountainArrayLinearSearch(int arr[], int size)
{
    int peakIdx = -1;
    int peakEle = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > peakEle)
        {
            peakEle = arr[i];
            peakIdx = i;
        }
    }
    return peakIdx;
}
int findPeakIndexInMountainArrayBinarySearch(int arr[], int size) {}
int main()
{
    system("cls");
    int arr[7] = {1, 2, 1, 3, 5, 6, 4};
    int size = 7;
    int peakIndex = findPeakIndexInMountainArrayLinearSearch(arr, size);
    cout << "Peak Index is LS " << peakIndex << endl;
    // int peakIndex1 = findPeakIndexInMountainArrayBinarySearch(arr, size);
    // cout << "Peak Index is BS " << peakIndex1 << endl;
    return 0;
}