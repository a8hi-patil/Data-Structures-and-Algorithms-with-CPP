#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    system("cls");
    char ch = 'a';
    char *ptr = &ch;
    ch++;
    // this line will print b
    cout << *ptr << endl;
    return 0;
}