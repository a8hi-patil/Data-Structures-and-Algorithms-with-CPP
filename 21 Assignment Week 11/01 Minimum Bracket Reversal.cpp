#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;
int countRev(string s)
{
    int len = s.length();
    if (len % 2)
        return -1;
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{')
        {
            st.push(s[i]);
        }
        else if (!st.empty() && s[i] == '}' && st.top() == '{')
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
    int c = 0;
    while (!st.empty())
    {
        char a = st.top();
        st.pop();
        char b = st.top();
        st.pop();
        if (a == b)
        {
            c++;
        }
        else
        {
            c += 2;
        }
    }
    return c;
}
int main()
{
    system("cls");
    string s = "}{{}}{{{";
    cout << countRev(s);
    return 0;
}