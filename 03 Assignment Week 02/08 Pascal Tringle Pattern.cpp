#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    system("cls");

    int n = 7;

    for (int i = 0; i <= n; i++)
    {
        int c = 1;

        for (int j = 1; j < i + 1; j++)
        {
            cout << c << " ";
            c = c * (i - j) / j;
        }
        cout << endl;
    }

    return 0;
}
