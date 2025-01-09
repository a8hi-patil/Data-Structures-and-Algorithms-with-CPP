#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
void solve(vector<string> &ans, int o, int c, string op, int n)
{
    if (o + c >= 2 * n)
    {
        ans.push_back(op);
        return;
    }

    if (o < n)
    {
        solve(ans, o + 1, c, op + "(", n);
    }

    if (c < o)
    {
        solve(ans, o, c + 1, op + ")", n);
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