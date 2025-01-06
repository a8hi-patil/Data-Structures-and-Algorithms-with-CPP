#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    system("cls");

    int a = 7;
    int *c = &a;

    c = c + 1;

    // this line will print 9 and next memory location

    cout << a << " " << *c << endl;

    return 0;
}