#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    system("cls");
    int n = 5;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < i + 1; j++)
        {
            cout << j + 1;
        }
        int temp = i;
        while (temp)
        {
            cout << temp--;
        }

        cout << endl;
    }

    return 0;
}