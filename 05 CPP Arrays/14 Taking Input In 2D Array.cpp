#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    system("cls");
    int arr[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    return 0;
}