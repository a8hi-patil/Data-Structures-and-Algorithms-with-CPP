#include <iostream>
#include <cstdlib>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
string removeDuplicatesT(string str, int k)
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
    string ans = "";
    if (!st.empty() && st.top().second == k)
    {
        st.pop();
    }
    while (!st.empty())
    {
        pair<char, int> top = st.top();
        while (top.second--)
        {
            ans.push_back(top.first);
        }
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    system("cls");
    string str = "yfttttfbbbbnnnnffbgffffgbbbbgssssgthyyyy";

    int k = 4;
    string ans = removeDuplicatesT(str, k);
    cout << "Ans string is " << ans << endl;
    return 0;
}