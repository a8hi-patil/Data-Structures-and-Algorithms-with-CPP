#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>
using namespace std;
void printV(vector<int> &v)
{
    for (auto u : v)
    {
        cout << u << " ";
    }
    cout << endl;
}

vector<int> interLeaveQueue(queue<int> &q1)
{
    int n = q1.size();
    int mid = n / 2;
    queue<int> q2;
    while (mid--)
    {
        q2.push(q1.front());
        q1.pop();
    }
    vector<int> ans;
    while (n)
    {
        ans.push_back(q2.front());
        q2.pop();
        ans.push_back(q1.front());
        q1.pop();
        n -= 2;
    }
    return ans;
}
int main()
{
    system("cls");
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    vector<int> ans = interLeaveQueue(q);
    printV(ans);
    return 0;
}