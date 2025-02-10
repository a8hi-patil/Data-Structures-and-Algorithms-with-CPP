#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;
vector<int> slidingWindow(vector<int> v, int k)
{
    // Process first window;
    vector<int> ans;
    queue<int> q;
    int min = INT_MAX;
    for (int i = 0; i < k; i++)
    {
        if (q.empty())
        {
            q.push(i);
        }
        else if (v[q.front()] > v[i])
        {
            q.pop();
            q.push(i);
        }
        else
        {
            q.push(i);
        }
    }
    // store ans ans slide
    int j = k;
    ans.push_back(q.front());
    while (j < v.size())
    {
        // remove front element in q if it is not in range
        if (j - k + 1 >= q.front())
        {
            q.pop();
        }
        while (!q.empty() && v[q.front()] > v[j])
        {
            q.pop();
        }
        if (q.empty())
        {
            q.push(j);
        }
        ans.push_back(q.front());
        j++;
    }
    return ans;
}
int main()
{
    system("cls");
    vector<int> a = {-8, 2, 3, -6, 10};
    int k = 3;
    vector<int> ans = slidingWindow(a, k);
    for (auto i : ans)
    {
        cout << a[i] << " ";
    }
    return 0;
}