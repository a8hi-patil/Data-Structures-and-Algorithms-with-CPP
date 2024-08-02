#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
void solve(vector<int> v, vector<int> &ans)
{
    stack<int> s;
    s.push(-1);
    for (int i = 0; i < v.size(); i++)
    {
        if (!s.empty() && s.top() < v[i])
        {
            ans.push_back(s.top());
            s.push(v[i]);
        }
        else
        {
            s.pop();
            ans.push_back(s.top());
            s.push(v[i]);
        }
    }
}
int main()
{
    system("cls");
    vector<int> v = {8, 4, 2, 6, 3};
    vector<int> ans;
    solve(v, ans);
    reverse(ans.begin(), ans.end());
    for (auto a : ans)
    {
        cout << a << " ,";
    }
    return 0;
}