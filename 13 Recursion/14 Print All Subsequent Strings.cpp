#include <iostream>
#include <cstdlib>
using namespace std;
void printSub(string s, int idx, string op)
{

    if (idx == s.length())
    {
        cout << op << endl;
        return;
    }
    printSub(s, idx + 1, op + s[idx]);
    printSub(s, idx + 1, op);
}
int main()
{
    system("cls");

    string s = "abc";
    string op = "";
    printSub(s, 0, op);
    return 0;
}