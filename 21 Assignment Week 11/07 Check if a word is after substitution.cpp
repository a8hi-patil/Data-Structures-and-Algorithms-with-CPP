#include <iostream>
#include <cstdlib>
using namespace std;
bool isValid(string s)
{
    if (s.length() == 0)
        return true;
    int found = s.find("abc");
    if (found != string::npos)
    {
        // found
        string left = s.substr(0, found);
        string right = s.substr(found + 3, s.length());
        return isValid(left + right);
    }
    return false;
}
bool isValid(string s)
{
    if (s[0] != 'a')
        return false;
    stack<char> st;

    for (char ch : s)
    {

        if (ch == 'a')
        {
            st.push(ch);
        }
        else if (ch == 'b' && !st.empty() && st.top() == 'a')
        {
            st.push(ch);
        }
        else if (ch == 'c' && !st.empty() && st.top() == 'b')
        {
            st.pop();
            st.pop();
        }
        else
        {
            return false;
        }
    }
    return st.empty();
}
int main()
{
    system("cls");
    return 0;
}