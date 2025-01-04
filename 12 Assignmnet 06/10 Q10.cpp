#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    system("cls");
    char *ptr;
    char str[] = "abcdefg";
    ptr = str;
    ptr += 5;
    // This will print fg
    cout << ptr << endl;
    return 0;
}