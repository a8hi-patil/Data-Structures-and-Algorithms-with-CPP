#include <iostream>
#include <cstdlib>
using namespace std;
void perm(string &s, int i)
{
    if (i == s.length())
    {
        cout << s << endl;
        return;
    }
    for (int j = i; j < s.length(); j++)
    {
        swap(s[i], s[j]);
        perm(s, i + 1);
        swap(s[i], s[j]);
    }
}
int main()
{
    system("cls");

    string a = "ABC";
    perm(a, 0);
    return 0;
}