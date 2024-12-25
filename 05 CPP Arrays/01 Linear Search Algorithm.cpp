#include <iostream>
#include <cstdlib>
using namespace std;

bool findTarget(int arr[], int target, int size)
{

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    system("cls");

    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;
    cout << "Enter Target : ";
    int target;
    cin >> target;

    if (findTarget(arr, target, size))
    {
        cout << "Target Found ::";
    }
    else
    {

        cout << "Target Not Found";
    }

    return 0;
}