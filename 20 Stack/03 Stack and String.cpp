#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;
int main()
{
    system("cls");
    string s = "Abhi";
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        st.push(s[i]);
    }
    s.erase();
    while (!st.empty())
    {
        char topEle = st.top();
        st.pop();
        s.push_back(topEle);
    }
    cout << s << endl;

    return 0;
}