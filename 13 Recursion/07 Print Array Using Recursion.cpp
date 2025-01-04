#include <iostream>
#include <cstdlib>
using namespace std;
void printArray(int a[], int size, int start)
{
    if (start >= size)
    {
        return;
    }
    cout << a[start] << " ";
    printArray(a, size, start + 1);
}
void printArrayR(int a[], int size, int end)
{
    if (end < 0)
        return;

    cout << a[end] << " ";
    printArrayR(a, size, end - 1);
}
int main()
{
    system("cls");
    int a[5] = {1, 2, 3, 4, 5};
    int size = 5;
    printArray(a, size, 0);
    cout << endl;
    printArrayR(a, size, size - 1);
    return 0;
}