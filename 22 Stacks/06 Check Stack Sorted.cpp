#include <iostream>
#include <cstdlib>
#include <stack>
using namespace std;
bool checkSort(stack<int> &s, int prev)
{
    if (s.empty())
    {
        return true;
    }
    int topEle = s.top();
    s.pop();
    if (prev > topEle)
    {
        prev = topEle;
    }
    else
    {
        s.push(topEle);
        return false;
    }
    bool ans = checkSort(s, prev);
    s.push(topEle);
    return ans;
}
int main()
{
    system("cls");
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(53);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    cout << checkSort(s, INT_MAX) << endl;
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}