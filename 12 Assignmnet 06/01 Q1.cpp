#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    system("cls");
    float f = 10.5;
    float p = 2.5;

    float *ptr = &f;

    (*ptr)++;
    *ptr = p;

    // this wil cout 2.5 25 2.5
    cout << *ptr << " " << f << " " << p << endl;

    return 0;
}