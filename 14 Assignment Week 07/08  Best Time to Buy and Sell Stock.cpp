#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int solve(vector<int> &a)
{
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for (int i = 0; i < a.size(); i++)
    {
        mini = min(mini, a[i]);
        int todaysprofit = a[i] - mini;
        maxi = max(maxi, todaysprofit);
    }
    return maxi <= 0 ? 0 : maxi;
}
void solve2(vector<int> &a, int p1, int &mini, int &maxi)
{
    if (p1 >= a.size())
    {
        return;
    }
    mini = min(mini, a[p1]);
    maxi = max(maxi, a[p1] - mini);
    solve2(a, p1 + 1, mini, maxi);
}
int main()
{
    system("cls");
    vector<int> prices = {7, 6, 4, 3, 1};
    cout << solve(prices) << endl;
    int maxi = INT_MIN;
    int mini = INT_MAX;
    int profit = -1;
    solve2(prices, 0, mini, maxi);
    cout << maxi << endl;
    return 0;
}