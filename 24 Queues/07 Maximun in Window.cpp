#include <iostream>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

vector<int> solve(vector<int> a, int k)
{
    vector<int> ans;
    queue<int> q;

    // First Window Procesing
    for (int i = 0; i < k; i++)
    {
        int el = a[i];

        while (!q.empty() && el > a[q.front()])
        {
            q.pop();
        }
        q.push(i);
    }
    // Remaining windows processing
    for (int i = k; i < a.size(); i++)
    {
        if (!q.empty())
        {
            ans.push_back(a[q.front()]);
        }
        else
        {
            ans.push_back(0);
        }
        if (!q.empty() && i - k == q.front())
        {
            q.pop();
        }
        int el = ans[i];

        while (!q.empty() && el > a[q.front()])
        {
            q.pop();
        }
        q.push(i);
    }
    // Last window processing
    for (int i = a.size() - k; i < a.size(); i++)
    {
        int el = a[i];

        while (!q.empty() && el > a[q.front()])
        {
            q.pop();
        }
        q.push(i);
    }
    if (!q.empty())
    {
        ans.push_back(a[q.front()]);
    }
    else
    {
        ans.push_back(0);
    }
    return ans;
}

int main()
{
    system("cls");
    vector<int> a = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> ans = solve(a, k);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}