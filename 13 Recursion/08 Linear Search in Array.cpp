#include <iostream>
#include <cstdlib>
using namespace std;

int find(int a[], int size, int start, int target)
{
    if (start >= size - 1)
        return -1;

    if (a[start] == target)
        return start;

    return find(a, size, start + 1, target);
}
int main()
{
    system("cls");
    int a[5] = {1, 2, 3, 4, 5};
    int size = 5;
    int target = 4;
    cout << "Target " << target << " found at index " << find(a, size, 0, target) << endl;
    return 0;
}