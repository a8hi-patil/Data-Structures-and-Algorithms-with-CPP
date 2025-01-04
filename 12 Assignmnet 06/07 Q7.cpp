#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    system("cls");
    int arr[] = {4, 5, 6, 7};
    int *p = (arr + 1);
    // this line will print 13
    cout << *arr + 9;
    return 0;
}