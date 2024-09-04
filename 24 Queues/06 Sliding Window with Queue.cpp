#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;
vector<int> slidingWindow(vector<int> &a, int k)
{
    queue<int> q;
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        int el = a[i];
        if (el < 0)
        {
            q.push(i);
        }
    }
    for (int i = k; i < a.size(); i++)
    {
        if (q.empty())
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(q.front());
            q.pop();
        }
        int el = a[i];
        if (el < 0)
        {
            q.push(i);
        }
    }
    return ans;
}
int main()
{
    system("cls");
    vector<int> a = {-8, 2, 3, -6, 10};
    int k = 2;
    vector<int> ans = slidingWindow(a, k);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}