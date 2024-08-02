#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;
void findMid(stack<int> &s, int count)
{
    if (count == 0)
    {
        cout << s.top() << endl;
        return;
    }
    int topEle = s.top();
    s.pop();
    findMid(s, count - 1);
    s.push(topEle);
}
int main()
{
    system("cls");
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    findMid(s, s.size() / 2);
    return 0;
}