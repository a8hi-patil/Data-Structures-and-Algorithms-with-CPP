#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    system("cls");
    int n = 5;
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    cout << fact;

    return 0;
}