#include <iostream>
#include <cstdlib>
using namespace std;

void sortZerosAndOnes(int arr[], int size)
{
    int first = 0, second = 1;

    while (second < size)
    {
        if (arr[first] == 0)
        {
            first++;
        }
        else if (arr[second] == 0)
        {
            swap(arr[second], arr[first]);
            second++;
            first++;
        }
        else
        {
            second++;
        }
    }
}

void methodTwo(int arr[], int size)
{
    int start = 0, end = size - 1;

    while (start < end)
    {
        if (arr[start] == 0)
        {
            start++;
        }
        else if (arr[end] == 1)
        {
            end--;
        }
        else
        {
            swap(arr[start], arr[end]);
        }
    }
}
int main()
{
    system("cls");
    int arr[] = {0, 1, 0, 0, 1, 1, 0};

    methodTwo(arr, 7);

    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}