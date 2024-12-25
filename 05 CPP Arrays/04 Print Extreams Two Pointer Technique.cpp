#include <iostream>
#include <cstdlib>
using namespace std;

void printExtreams(int arr[], int size)
{
    int start = 0, end = size - 1;

    while (start <= end)
    {
        cout << arr[start] << "-" << arr[end] << endl;
        start++;
        end--;
    }
}

int main()
{
    system("cls");
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;
    printExtreams(arr, size);
    return 0;
}