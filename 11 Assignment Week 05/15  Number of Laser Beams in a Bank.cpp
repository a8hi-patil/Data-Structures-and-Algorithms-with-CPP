#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
int cnt(string s)
{
    int c = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
            c++;
    }
    return c;
}
int main()
{
    system("cls");
    vector<string> bank = {"011001", "000000", "010100", "001000"};

    int t = 0, c = 0, p = 0;
    for (int i = 0; i < bank.size(); i++)
    {
        if (c != 0)
        {
            p = c;
        }
        c = cnt(bank[i]);

        t = t + (p * c);
    }

    cout << t;

    return 0;
}