#include <iostream>
#include <cstdlib>
using namespace std;

void rem(string &s, string &p)
{
    if (s.find(p) != string ::npos)
    {
        string left = s.substr(0, s.find(p));
        string right = s.substr(s.find(p) + p.length(), s.length());
        s = left + right;
        rem(s, p);
    }
    else
    {
        return;
    }
}
int main()
{
    system("cls");
    string s = "daabcbaabcbc", part = "abc";
    rem(s, part);
    cout << "Ans :" << s << endl;
    return 0;
}