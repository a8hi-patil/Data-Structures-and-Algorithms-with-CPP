#include <iostream>
#include <cstdlib>
using namespace std;

void changesign(int *p)
{
    *p = (*p) * -1;
}
int main()
{
    system("cls");
    int a = 10;
    changesign(&a);

    // this line will print -10;
    cout << a;
    return 0;
}