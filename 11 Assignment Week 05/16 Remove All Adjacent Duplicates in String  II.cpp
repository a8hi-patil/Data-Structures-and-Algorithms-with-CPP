#include <iostream>
#include <cstdlib>
#include <stack>
#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string str, int k)
{
    stack<pair<char, int>> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (!st.empty() && st.top().second == k)
        {
            st.pop();
        }
        if (st.empty())
        {
            st.push({str[i], 1});
        }
        else
        {
            if (st.top().first == str[i])
            {
                st.top().second++;
            }
            else
            {
                st.push({str[i], 1});
            }
        }
    }
    if (!st.empty() && st.top().second == k)
    {
        st.pop();
    }
    string ans = "";
    while (!st.empty())
    {
        while (st.top().second)
        {

            ans.push_back(st.top().first);
            st.top().second--;
        }

        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    system("cls");

    string s = "deeedbbcccbdaa";
    int k = 3;
    cout << removeDuplicates(s, 3);
    return 0;
}