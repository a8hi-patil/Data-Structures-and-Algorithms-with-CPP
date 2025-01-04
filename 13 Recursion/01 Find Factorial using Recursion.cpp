#include <iostream>
#include <cstdlib>
using namespace std;

int fat(int num)
{
    if (num == 1 || num == 0)
    {
        return 1;
    }
    return num * fat(num - 1);
}

int main()
{
    system("cls");
    cout << fat(5);
    return 0;
}