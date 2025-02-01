#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;
bool checkSorted(stack<int> &st, int prev)
{
    if (st.empty())
        return true;

    int curr = st.top();
    st.pop();
    if (curr >= prev)
    {
        prev = curr;
        return checkSorted(st, prev);
    }
    return false;
}

int main()
{
    system("cls");
    stack<int> st;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(22);
    st.push(2);
    st.push(1);
    int prev = INT_MIN;
    cout << checkSorted(st, prev);
    return 0;
}