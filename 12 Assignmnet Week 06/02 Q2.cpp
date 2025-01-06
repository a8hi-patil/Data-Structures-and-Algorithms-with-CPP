#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    system("cls");
    int a = 7;
    int b = 17;
    int *c = &b;

    *c = 7;

    // this line will print  7 7
    cout << a << " " << b;

    return 0;
}