#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
using namespace std;
bool isValid(string str)
{
    if (str[0] == ')' || str[0] == ']' || str[0] == '}')
    {
        return false;
    }
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            s.push(str[i]);
        }
        else
        {
            char ch = str[i];
            if (!s.empty() && s.top() == '(' && ch == ')')
            {
                s.pop();
            }
            else if (!s.empty() && s.top() == '[' && ch == ']')
            {
                s.pop();
            }
            else if (!s.empty() && s.top() == '{' && ch == '}')
            {
                s.pop();
            }
            else
            {
                s.push(ch);
            }
        }
    }
    if (s.size() == 0)
    {
        return true;
    }
    return false;
}

int main()
{
    system("cls");
    string s = "())[]{}";
    cout << isValid(s);
    return 0;
}