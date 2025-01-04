#include <iostream>
#include <cstdlib>
using namespace std;

void square(int *p)
{
    int a = 10;
    p = &a;

    *p = *p * *p;
}
int main()
{
    system("cls");
    int a = 10;
    square(&a);
    // this line will print 10
    cout << a << endl;
    return 0;
}