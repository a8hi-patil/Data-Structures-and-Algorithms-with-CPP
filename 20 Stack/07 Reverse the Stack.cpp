#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;
void insertAtHead(stack<int> &st, int val)
{
    if (st.empty())
    {
        st.push(val);
        return;
    }
    int top = st.top();
    st.pop();
    insertAtHead(st, val);
    st.push(top);
}
void reverseStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }

    int top = st.top();
    st.pop();
    reverseStack(st);
    insertAtHead(st, top);
}

int main()
{
    system("cls");
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    reverseStack(st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}