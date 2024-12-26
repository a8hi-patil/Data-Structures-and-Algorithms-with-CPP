#include <iostream>
#include <cstdlib>
using namespace std;
int squareRoot(int n)
{
    int start = 0;
    int end = n;
    int mid = start + (end - start) / 2;

    while (start <= end)
    {
        if (mid * mid == n)
        {
            return mid;
        }
        else if (mid * mid > n)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}
int main()
{
    system("cls");
    int n;
    cout << "Enter number : ";
    cin >> n;
    cout << "Square root of number " << n << " is : " << squareRoot(n) << endl;
    return 0;
}