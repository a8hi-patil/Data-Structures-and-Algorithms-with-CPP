#include <iostream>
#include <cstdlib>
using namespace std;
bool findPalindrom(char arr[], int size)
{
    int l = 0;
    int h = size - 1;

    while (l < h)
    {
        if (arr[l++] != arr[h--])
            return false;
    }
    return true;
}
int main()
{
    system("cls");
    char name[] = {
        'n',
        'i',
        't',
        'i',
        'n'};
    int size = 5;
    if (findPalindrom(name, size))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
    return 0;
}