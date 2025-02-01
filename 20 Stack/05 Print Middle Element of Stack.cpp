#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;
void printMid(stack<int> &st, int c)
{
    if (c == 0)
    {
        int top = st.top();
        cout << top << endl;
        return;
    }
    int top = st.top();
    st.pop();
    printMid(st, c - 1);
    st.push(top);
}
int main()
{
    system("cls");
    stack<int> st;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);
    printMid(st, st.size() / 2);
    return 0;
}