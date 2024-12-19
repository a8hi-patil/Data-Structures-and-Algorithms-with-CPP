#include <iostream>
#include <cstdlib>
using namespace std;

void printDigits(int n)
{
    while (n)
    {
        cout << n % 10 << endl;

        n = n / 10;
    }
}

int main()
{
    system("cls");
    cout << "Enter a number : ";
    int num;
    cin >> num;
    printDigits(num);
    return 0;
}