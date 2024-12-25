#include <iostream>
#include <cstdlib>
using namespace std;

int negativeMarking(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            continue;
        }
        else
        {
            arr[arr[i]] *= -1;
        }
    }
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > 0)
            return i;
    }
    return -1;
}

int main()
{
    system("cls");
    int arr[5] = {3, 0, 1};
    int size = 3;

    int missingNumber = negativeMarking(arr, size);
    cout << "Missing number is " << missingNumber << endl;
    return 0;
}