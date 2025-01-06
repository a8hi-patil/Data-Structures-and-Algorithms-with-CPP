#include <iostream>
#include <cstdlib>
using namespace std;

bool solve(string &s, int si, string &p, int pi)
{

    if (si == s.length() && pi == p.length())
    {
        return true;
    }
    if (si == s.length() && pi < p.length())
    {

        while (pi < p.length())
        {
            if (p[pi] != '*')
            {
                return false;
            }
            pi++;
        }
        return true;
    }
    if (s[si] == p[pi] || p[pi] == '?')
    {
        return solve(s, si + 1, p, pi + 1);
    }
    if (p[pi] == '*')
    {
        bool caseA = solve(s, si, p, pi + 1);
        bool caseB = solve(s, si + 1, p, pi);

        return caseA || caseB;
    }
    return false;
}
bool isMatch(string &s, string &p)
{
    int si = 0;
    int pi = 0;

    return solve(s, si, p, pi);
}
int main()
{
    system("cls");
    string s = "aa", p = "*";
    return 0;
}