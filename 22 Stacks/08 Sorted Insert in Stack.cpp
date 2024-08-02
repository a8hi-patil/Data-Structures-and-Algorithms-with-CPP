#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;
void sortedInsert(stack<int> &s, int val)
{
    if (s.empty())
    {
        s.push(val);
        return;
    }
    if (!s.empty() && s.top() < val)
    {
        s.push(val);
        return;
    }
    int topEle = s.top();
    s.pop();
    sortedInsert(s, val);
    s.push(topEle);
}
int main()
{
    system("cls");
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    s.push(5);
    s.push(6);
    s.push(7);
    int val = 4;
    sortedInsert(s, val);
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}