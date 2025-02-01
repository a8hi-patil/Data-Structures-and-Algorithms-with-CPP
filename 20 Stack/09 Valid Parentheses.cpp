#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
using namespace std;
bool isValid(string s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (st.empty() && (s[i] == ')' || s[i] == ']' || s[i] == '}'))
        {
            return false;
        }
        char currChar = s[i];
        if (st.empty())
        {
            st.push(currChar);
            continue;
        }
        switch (currChar)
        {
        case ')':
            if (st.top() == '(')
            {
                st.pop();
                continue;
            }
            break;
        case ']':
            if (st.top() == '[')
            {
                st.pop();
                continue;
            }
            break;
        case '}':
            if (st.top() == '{')
            {
                st.pop();
                continue;
            }
            break;
        }
        st.push(currChar);
    }
    return st.empty();
}
void test(vector<string> &ip, vector<bool> &op)
{
    for (int i = 0; i < ip.size(); i++)
    {
        bool yourAns = isValid(ip[i]);
        bool realAns = op[i];

        string ans = yourAns == realAns ? "PASSED " : "FAILED ";
        cout << "Test Case " << i + 1 << " " << ans << endl;
        cout << "Input : " << ip[i] << endl;
        string yAns = yourAns ? "True" : "False";
        string rAns = realAns ? "True" : "False";
        cout << "Your answer :" << yAns << endl;
        cout << "Expeacted answer :" << rAns << endl;
    }
}
int main()
{
    system("cls");
    vector<string> ips = {"()", "()[]{}", "(]", "([])"};
    vector<bool> ans = {1, 1, 0, 1};
    test(ips, ans);
    return 0;
}