#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
void solve(vector<string> &ans, int open, int close, string output, int n)
{
    if (open + close >= 2 * n)
    {
        ans.push_back(output);
        return;
    }
    if (open < n)
    {
        solve(ans, open + 1, close, output + "(", n);
    }
    if (close < open)
    {
        solve(ans, open, close + 1, output + ")", n);
    }
}
int main()
{
    system("cls");
    vector<string> ans;
    int n = 3;
    solve(ans, 0, 0, "", n);
    for (auto a : ans)
    {
        cout << a << endl;
    }

    return 0;
}