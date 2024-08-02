#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;
void insertAtHead(stack<int> &s, int val)
{
    if (s.empty())
    {
        s.push(val);
        return;
    }
    int topEle = s.top();
    s.pop();
    insertAtHead(s, val);
    s.push(topEle);
}
void reverseTheStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }
    int topEle = s.top();
    s.pop();
    reverseTheStack(s);
    insertAtHead(s, topEle);
}
int main()
{
    system("cls");
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    reverseTheStack(s);
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}