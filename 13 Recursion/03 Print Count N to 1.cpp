#include <iostream>
#include <cstdlib>
using namespace std;
void print(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    print(n - 1);
}
int main()
{
    system("cls");
    int n = 10;
    print(n);
    return 0;
}