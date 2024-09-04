#include <iostream>
#include <cstdlib>
#include <queue>
#include <stack>
using namespace std;
void reverseKGroupInQueue(queue<int> &q, int k, int count)
{
    if (count < k)
    {
        for (int i = 0; i < count; i++)
        {
            int ele = q.front();
            q.pop();
            q.push(ele);
        }
    }
    else
    {
        stack<int> st;
        for (int i = 0; i < k; i++)
        {
            st.push(q.front());
            q.pop();
        }
        while (!st.empty())
        {
            q.push(st.top());
            st.pop();
        }
        reverseKGroupInQueue(q, k, count - k);
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
    q.push(6);
    q.push(7);
    int k = 3;
    int count = q.size();
    reverseKGroupInQueue(q, k, count);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}