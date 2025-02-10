#include <iostream>
#include <cstdlib>
#include <queue>
#include <stack>
using namespace std;
void revQuue(queue<int> &q)
{
    if (q.empty())
        return;
    int front = q.front();
    q.pop();
    revQuue(q);
    q.push(front);
}
void revQuesStack(queue<int> &q)
{
    stack<int> st;
    while (!q.empty())
    {
        int frnt = q.front();
        q.pop();
        st.push(frnt);
    }
    while (!st.empty())
    {
        int frnt = st.top();
        st.pop();
        q.push(frnt);
    }
}
int main()
{
    system("cls");
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    revQuue(q);
    revQuesStack(q);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}