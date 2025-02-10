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
    queue<int> q2;
    int mid = q1.size() / 2;
    while (mid--)
    {
        q2.push(q.front());
        q.pop();
    }
    vector<int> ans;
    while (!q.empty())
    {
        ans.push_back(q2.front);
        q2.pop();
        ans.push_back(q.front());
        q.pop();
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