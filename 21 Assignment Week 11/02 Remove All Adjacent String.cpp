#include <iostream>
#include <cstdlib>
#include <stack>
#include <algorithm>
using namespace std;
string solve(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (st.empty())
        {
            st.push(s[i]);
        }
        else if (!st.empty() && st.top() == s[i])
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
    string ans = "";
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    system("cls");
    string s = "abbacb";

    cout << solve(s) << endl;
    return 0;
}