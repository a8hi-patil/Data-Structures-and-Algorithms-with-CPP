#include <iostream>
using namespace std;

int main()
{

    int n = 3;
    int m = 10;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << "* ";
        cout << endl;
    }
    return 0;
}