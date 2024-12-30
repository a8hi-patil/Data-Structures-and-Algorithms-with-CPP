#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int calDev(string &s)
{
    int c = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
            c++;
    }
    return c;
}
int numberOfBeams(vector<string> &bank)
{
    int total = 0;
    int cur = 0;
    int pre = 0;
    for (int i = 0; i < bank.size(); i++)
    {
        if (cur != 0)
        {
            pre = cur;
        }
        cur = calDev(bank[i]);

        total = total + (cur * pre);
    }
    return total;
}
void test(vector<string> &a, int op)
{
    int ans = numberOfBeams(a);
    bool flag = true;
    if (ans == op)
    {
        flag = true;
    }
    else
    {
        flag = false;
    }
    string msg = flag ? "Passed " : "Failed ";

    cout << msg << ": " << "Expected " << op << " Output " << ans << endl;
}
int main()
{
    system("cls");
    vector<vector<string>> inp = {{"011001", "000000", "010100", "001000"}, {"000", "111", "000"}};
    vector<int> op = {8, 0};

    for (int i = 0; i < inp.size(); i++)
    {
        test(inp[i], op[i]);
    }

    // vector<string> bank = {"011001", "000000", "010100", "001000"};
    // cout << numberOfBeams(bank);
    return 0;
}