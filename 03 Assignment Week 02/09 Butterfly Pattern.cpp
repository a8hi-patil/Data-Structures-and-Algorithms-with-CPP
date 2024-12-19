#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    system("cls");

    int n = 7;

    for (int i = 0; i < 2 * n; i++)
    {
        int cond = i < n ? i : n + (n - i - 1);
        int spaceCount = i < n ? 2 * (n - i - 1) : i - cond - 1;

        for (int j = 0; j < 2 * n; j++)
        {
            if (j <= cond)
            {
                cout << "*";
            }
            else if (spaceCount > 0)
            {
                cout << " ";
                spaceCount--;
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }

    return 0;
}