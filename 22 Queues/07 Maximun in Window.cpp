#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

vector<int> solve(vector<int> v, int k)
{
    vector<int> ans;
    deque<int> q;
    // process first window
    for (int i = 0; i < k; i++)
    {

        while (!q.empty() && v[i] > v[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    ans.push_back(v[q.front()]);

    // process remaining windows
    int i = k;
    while (i < v.size())
    {
        // check q front lies in range or not
        if (!q.empty() && i - k + 1 > q.front())
        {
            q.pop_front();
        };
        // add next element
        while (!q.empty() && v[i] > v[q.back()])
        {
            q.pop_back();
        }

        q.push_back(i);

        ans.push_back(v[q.front()]);
        i++;
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