#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    system("cls");
    int n = 5;
    int val = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << val++ << " ";
        }
        cout << endl;
    }

    return 0;
}