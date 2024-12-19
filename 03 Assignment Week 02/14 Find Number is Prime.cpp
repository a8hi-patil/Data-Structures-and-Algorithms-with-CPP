#include <iostream>
#include <cstdlib>
using namespace std;

bool isPrime(int n)
{
    bool flag = true;

    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i)
        {
            continue;
        }
        else
        {
            flag = false;
            break;
        }
    }
    return flag;
}

int main()
{
    system("cls");
    int n;
    cout << "Enter number : ";
    cin >> n;

    if (isPrime(n))
    {
        cout << "Is prime";
    }
    else
    {
        cout << "Not prime";
    }

    return 0;
}