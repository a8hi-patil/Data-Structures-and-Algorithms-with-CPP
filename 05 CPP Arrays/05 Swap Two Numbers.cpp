#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    system("cls");
    int a = 5;
    int b = 99;

    cout << a << " " << b;
    cout << "After swappint" << endl;
    a = a + b;
    b = a - b;
    a = a - b;
    cout << a << " " << b;
    return 0;
}