#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

void insertAtBottom(int val, stack<int> &st)
{
    if (st.empty())
    {
        st.push(val);
        return;
    }
    int top = st.top();
    st.pop();
    insertAtBottom(val, st);
    st.push(top);
}
int main()
{
    system("cls");
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    insertAtBottom(5, st);
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        cout << top << " ";
    }

    return 0;
}