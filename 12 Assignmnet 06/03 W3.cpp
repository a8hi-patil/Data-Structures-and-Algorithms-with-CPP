#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    system("cls");
    int *ptr = 0;
    int a = 10;
    *ptr = a;

    // this line wil print
    cout << *ptr;

    return 0;
}
