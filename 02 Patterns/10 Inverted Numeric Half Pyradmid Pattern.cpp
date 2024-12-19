#include <iostream>
using namespace std;

int main()
{
    int n = 6;
    int counter = 21;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << counter-- << " ";
        }
        cout << endl;
    }
    return 0;
}