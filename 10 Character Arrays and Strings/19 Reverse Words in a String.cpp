#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

string reverserTheWordsOfString(string &s)
{
    stack<char> st;
    string ans = "";
    int j = s.length() - 1;

    while (j >= 0)
    {

        char c = s[j];
        if (c == ' ')
        {
            cout << "c :" << c << endl;
            while (s[j] == ' ' && j >= 0)
            {
                // cout << "Skiping" << endl;
                j--;
            }

            j++;
            if (ans.length() != 0)
            {

                st.push(' ');
            }
            while (!st.empty())
            {
                ans.push_back(st.top());
                st.pop();
            }
            st.push(c);
        }
        else
        {
            cout << "c :" << c << endl;
            st.push(c);
        }
        j--;
    }
    while (!st.empty())
    {

        char top = st.top();
        cout << "==" << top << endl;
        if (top != ' ')
        {
            /* code */
            ans.push_back(st.top());
        }

        st.pop();
    }
    ans.pop_back();
    return ans;
}

int main()
{
    system("cls");
    // string s = "the sky is blue";
    // string s = "    jinat yedi       hai      ";
    string s = "   a abhi patil good   example";
    string f = reverserTheWordsOfString(s);
    cout << "->" << f << "<-" << endl;
    return 0;
}