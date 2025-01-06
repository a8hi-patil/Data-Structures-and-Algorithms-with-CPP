#include <iostream>
#include <cstdlib>
using namespace std;
int solve(int n, int k, int t)
{
    if (t < 0)
        return 0;
    if (n == 0 && t == 0)
        return 1;
    if (n == 0 && t != 0)
        return 0;
    if (n != 0 && t == 0)
        return 0;

    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += solve(n - 1, k, t - i);
    }
    return ans;
}
int main()
{
    system("cls");
    int n = 2, k = 6, target = 7;
    cout << solve(n, k, target);
    return 0;
}