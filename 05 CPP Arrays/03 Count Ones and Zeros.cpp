#include <iostream>
#include <cstdlib>
using namespace std;

void countOnesAndZeros(int arr[], int size)
{
    int countOfOne = 0, countOfZero = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            countOfZero++;
        }
        else if (arr[i] == 1)
        {
            countOfOne++;
        }
    }

    cout << "Count of zero " << countOfZero << endl;
    cout << "Count of One " << countOfOne << endl;
}

int main()
{
    system("cls");
    int arr[] = {1, 0, 1, 1, 0, 0, 1, 2, 0};
    countOnesAndZeros(arr, 9);
    return 0;
}