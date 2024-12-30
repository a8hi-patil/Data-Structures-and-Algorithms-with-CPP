#include <iostream>
#include <cstdlib>
using namespace std;
void reverse(char arr[], int size)
{
    int l = 0;
    int h = size - 1;

    while (l < h)
    {
        swap(arr[l], arr[h]);
        l++;
        h--;
    }
}
int main()
{
    system("cls");
    char name[] = {'a', 'b', 'h', 'i', '\0'};
    int size = 4;
    reverse(name, size);
    cout << name;
}