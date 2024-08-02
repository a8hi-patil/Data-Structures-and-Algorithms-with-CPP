#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int val)
{
    if (s.empty())
    {
        s.push(val);
        return;
    }
    int prevVal = s.top();
    s.pop();
    insertAtBottom(s, val);
    s.push(prevVal);
}
int main()
{
    system("cls");
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    int val = 9;
    insertAtBottom(s, val);
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}