#include <iostream>
#include <cstdlib>
using namespace std;

int findLastCharLR(string s, char sC, int start, int found)
{
    if (start >= s.length())
    {
        return found;
    }
    if (s[start] == sC)
    {
        found = start;
    }
    return findLastCharLR(s, sC, start + 1, found);
}
int findLastCharRL(string s, char sC, int end)
{

    if (s[end] == sC)
    {
        return end;
    }
    if (end < 0)
    {
        return -1;
    }
    return findLastCharRL(s, sC, end - 1);
}
int main()
{
    system("cls");
    string str = "ssssas";
    char s = 's';
    cout << findLastCharLR(str, s, 0, -1) << endl;
    cout << findLastCharRL(str, s, str.length() - 1);
    return 0;
}