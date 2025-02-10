#include <iostream>
#include <cstdlib>
#include <queue>
#include <stack>
using namespace std;
void revInKGrps(queue<int> &q, int k, int n)
{
    if (n < k)
    {
        for (int i = 0; i < n; i++)
        {
            q.push(q.front());
            q.pop();
        }
        return;
    }
    stack<int> st;
    int itr = k;
    while (itr--)
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    revInKGrps(q, k, n - k);
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
    q.push(8);
    q.push(9);
    q.push(10);
    q.push(11);

    revInKGrps(q, 3, q.size());
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}