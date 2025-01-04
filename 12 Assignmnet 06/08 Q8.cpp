#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    system("cls");
    char s[] = "hello";
    char *p = s;

    // this will print h and h
    cout << s[0] << "-" << p[0] << endl;
    return 0;
}