#include <iostream>
#include <cstdlib>
using namespace std;
int sum(int n)
{
    if (n == 1)
    {
        return n;
    }
    return n + sum(n - 1);
}
int main()
{
    system("cls");
    cout << "The sum of numbers 1 to " << 5 << " are = " << sum(5) << endl;
    cout << "The sum of numbers 1 to " << 10 << " are = " << sum(10) << endl;
    cout << "The sum of numbers 1 to " << 3 << " are = " << sum(3) << endl;
    return 0;
}