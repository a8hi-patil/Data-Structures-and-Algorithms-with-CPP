#include <iostream>
#include <cstdlib>
using namespace std;

void convert(int c)
{
    cout << c << " C is " << c + 271.15 << " in Kelvin and " << c * 1.8 + 32 << " in fareheite";
}
int main()
{
    system("cls");
    cout << "Enter temperature in C";
    int c;
    cin >> c;
    convert(c);
    return 0;
}