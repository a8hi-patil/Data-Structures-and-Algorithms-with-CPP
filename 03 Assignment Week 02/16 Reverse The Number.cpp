#include <iostream>
#include <cstdlib>
using namespace std;
int revNum(int n)
{

    bool isNegative = n < 0 ? true : false;

    if (isNegative)
        n *= -1;
    int ans = 0;
    while (n)
    {
        int digit = n % 10;
        n = n / 10;
        ans = ans * 10 + digit;
    }

    return isNegative ? -ans : ans;
}
int main()
{
    system("cls");
    int n = 5356;
    int r = -5356;

    cout << revNum(n);
    cout << endl;
    cout << revNum(r);
    return 0;
}