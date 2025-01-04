#include <iostream>
#include <cstdlib>
using namespace std;
bool checkSortA(int a[], int start, int size)
{

    if (start >= size - 1)
    {
        return true;
    }

    if (a[start] > a[start + 1])
    {
        return false;
    }
    return checkSortA(a, start + 1, size);
}
bool checkSortD(int a[], int end, int size)
{
    if (end <= 0)
    {
        return true;
    }

    if (a[end] > a[end - 1])
    {
        return false;
    }
    return checkSortD(a, end - 1, size);
}
int main()
{
    system("cls");
    int a[5] = {1, 2, 3, 4, 3};
    cout << checkSortA(a, 0, 5) << endl;
    int b[5] = {5, 1, 3, 2, 1};
    cout << checkSortD(b, 4, 5) << endl;
    int c[5] = {1, 2, 3, 4, 5};
    cout << checkSortA(c, 0, 5) << endl;
    int d[5] = {5, 4, 3, 2, 1};
    cout << checkSortD(d, 4, 5) << endl;

    return 0;
}