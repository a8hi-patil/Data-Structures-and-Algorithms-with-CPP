#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    system("cls");
    char arr[20];
    int i;
    for (i = 0; i < 10; i++)
    {
        *(arr + i) = 65 + i;
    }
    *(arr + i) = '\0';
    // this line will print AtoJ
    cout << arr << endl;

    return 0;
}