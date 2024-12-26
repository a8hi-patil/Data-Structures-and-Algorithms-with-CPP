#include <iostream>
#include <cstdlib>
using namespace std;
double squareWithPrecision(int num)
{
    double start = 0;
    double end = num;
    double mid = start + (end - start) / 2;
    double ans = -1;
    while ((end - start) >= 0.001)
    {
        double prod = mid * mid;
        if (prod == num)
        {
            return mid;
        }
        else if (prod > num)
        {
            end = mid - 0.001;
        }
        else
        {
            start = mid + 0.001;
            ans = mid;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}
int main()
{
    system("cls");
    cout << "Enter a number : ";
    int num;
    cin >> num;
    cout << "Square root of the number " << num << " is " << squareWithPrecision(num) << endl;
    return 0;
}