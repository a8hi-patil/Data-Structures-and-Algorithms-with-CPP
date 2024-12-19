#include <iostream>
#include <cstdlib>
using namespace std;
void count(int n)
{
    int c = 0;

    while (n)

    {
        if (n & 1)
        {
            c++;
        }
        n = n >> 1;
    }
    cout << c;
}
int main()
{
    system("cls");
    int n;
    cin >> n;
    count(n);
    return 0;
}