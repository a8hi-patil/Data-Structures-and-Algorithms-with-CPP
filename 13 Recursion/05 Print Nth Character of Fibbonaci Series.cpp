#include <iostream>
#include <cstdlib>
using namespace std;
int fibb(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n == 2)
    {
        return 1;
    }

    return fibb(n - 1) + fibb(n - 2);
}
int main()
{
    system("cls");
    cout << "The " << 5 << "th fibbonaci number is " << fibb(5) << endl;
    return 0;
}