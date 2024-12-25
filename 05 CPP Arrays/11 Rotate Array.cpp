#include <iostream>
#include <cstdlib>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void rotateArrayByKPlaces(int arr[], int size, int shift)
{

    // First make one array of size shift and insert values

    int *temp = new int[shift];
    int tempInx = 0;
    for (int i = size - shift; i < size; i++)
    {
        temp[tempInx] = arr[i];
        tempInx++;
    }

    // shifting all valus by shift places
    int tempPointer = size - shift - 1;
    while (tempPointer >= 0)
    {
        arr[tempPointer + shift] = arr[tempPointer];
        tempPointer--;
    }

    for (int i = 0; i < shift; i++)
    {
        arr[i] = temp[i];
    }
}

int main()
{
    system("cls");
    int arr[5] = {10, 20, 30, 40, 50};
    int size = 5;
    int shift = 2;
    printArray(arr, size);
    rotateArrayByKPlaces(arr, size, shift);
    printArray(arr, size);
    return 0;
}