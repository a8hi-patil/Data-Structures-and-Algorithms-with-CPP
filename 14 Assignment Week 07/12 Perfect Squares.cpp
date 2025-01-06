#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int numSquaresHelper(int n)
{

    if (n == 0)
        return 1;
    if (n < 0)
        return 0;

    int ans = INT_MAX;
    int i = 1;
    int end = sqrt(n);

    while (i <= end)
    {
        int sqaure = i * i;
        int perfectSquaresAns = 1 + numSquaresHelper(n - sqaure);
        if (perfectSquaresAns < ans)
        {
            ans = perfectSquaresAns;
        }
        i++;
    }
    return ans;
}
int numSquares(int n)
{
    return numSquaresHelper(n) - 1;
}
int main()
{
    system("cls");
    int n = 12;
    cout << numSquares(n) << endl;
    return 0;
}