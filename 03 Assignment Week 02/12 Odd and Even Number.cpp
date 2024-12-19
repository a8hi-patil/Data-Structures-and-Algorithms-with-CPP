#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    system("cls");
    cout << "Enter Number : ";
    int num;
    cin >> num;

    if (num % 2)
    {
        cout << "ODD";
        return 0;
    }
    cout << "EVEN";

    return 0;
}