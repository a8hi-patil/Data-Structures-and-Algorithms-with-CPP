#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
string removeSubString(string s, string sub)
{
    while (s.find(sub) != string ::npos)
    {
        s.erase(s.find(sub), sub.length());
    }
    return s;
}
int main()
{
    system("cls");
    string s = "daabcbaabcbc", part = "abc";
    string ans = removeSubString(s, part);
    cout << "Ans is " << ans;
    return 0;
}