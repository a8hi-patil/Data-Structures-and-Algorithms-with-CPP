#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
void findNextSmaller(vector<int> &ip, vector<int> &op)
{
    stack<int> st;
    st.push(-1);

    for (int i = ip.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() != -1 && ip[st.top()] >= ip[i])
            st.pop();
        op.push_back(st.top());
        st.push(i);
    }
    reverse(op.begin(), op.end());
}
void findPrevSmaller(vector<int> &ip, vector<int> &op)
{
    stack<int> st;
    st.push(-1);

    for (int i = 0; i < ip.size(); i++)
    {
        while (!st.empty() && st.top() != -1 && ip[st.top()] > ip[i])
            st.pop();
        op.push_back(st.top());
        st.push(i);
    }
}
int main()
{
    system("cls");
    vector<int> ip = {3, 1, 2};
    vector<int> nextSmaller;
    vector<int> prevSmaller;
    findNextSmaller(ip, nextSmaller);
    findPrevSmaller(ip, prevSmaller);
    int sum = 0;

    for (int i = 0; i < ip.size(); i++)
    {
        int nexti = nextSmaller[i] == -1 ? ip.size() : nextSmaller[i];
        int previ = prevSmaller[i];
        int right = nexti - i;
        int left = i - previ;
        sum = sum + ((right * left) * ip[i]);
    }
    cout << sum << endl;
    return 0;
}