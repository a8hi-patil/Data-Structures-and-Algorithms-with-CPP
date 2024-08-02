#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
using namespace std;
int main()
{
    system("cls");
    stack<char> s;
    string str = "Abhi";
    for (int i = 0; i < str.length(); i++)
        s.push(str[i]);
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }

    return 0;
}