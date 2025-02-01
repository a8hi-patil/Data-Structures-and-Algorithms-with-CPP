#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;
void sortedInsert(stack<int> &st, int val)
{
    if (st.empty())
    {
        st.push(val);
        return;
    }
    if (st.top() < val)
    {
        st.push(val);
        return;
    }
    int top = st.top();
    st.pop();
    sortedInsert(st, val);
    st.push(top);
}
int main()
{
    system("cls");
    stack<int> st;
    st.push(1);
    st.push(2);
    // st.push(3);
    st.push(4);
    st.push(5);
    sortedInsert(st, 0);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}