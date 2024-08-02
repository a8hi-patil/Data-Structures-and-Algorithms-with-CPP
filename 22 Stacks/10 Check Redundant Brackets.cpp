#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
using namespace std;
int countRedundantBrackets(string str)
{
    stack<char> s;
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == ')' || str[i] == '+')
        {
            if (str[i] == '(' || str[i] == '+')
            {
                s.push(str[i]);
            }
            else
            {
                if (!s.empty() && s.top() == '(')
                {
                    count++;
                    s.push(str[i]);
                }
            }
        }
    }
    return count;
}
int main()
{
    system("cls");
    string str = "((a+b))";
    cout << countRedundantBrackets(str) << endl;
    return 0;
}