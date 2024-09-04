#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reveseQueueUsingStack(queue<int> &q)
{
    stack<int> st;
    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
}
void reveseQueueUsingRec(queue<int> &q)
{
    if (q.empty())
    {

        return;
    }
    int ele = q.front();
    q.pop();
    reveseQueueUsingRec(q);
    q.push(ele);
}
int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(7);

    reveseQueueUsingRec(q);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}