#include <iostream>
#include <cstdlib>
using namespace std;

void rev(string &str, int s, int e)
{
    if (s > e)
    {
        return;
    }
    swap(str[s], str[e]);
    rev(str, s + 1, e - 1);
}
int main()
{
    system("cls");
    string s = "abcd";
    rev(s, 0, s.length() - 1);
    cout << s;
    return 0;
}