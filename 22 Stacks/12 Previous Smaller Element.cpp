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
        int element = v[i];
        while(s.top() >= element) {
      s.pop();
    }
    
    ans.push_back(s.top());
    
    s.push(element);
    }
}
int main()
{
    system("cls");
    // vector<int> v = {8, 4, 2, 6, 3};
     vector<int> v = {4, 2, 0, 3, 2, 4, 3, 4};
    vector<int> ans;
    solve(v, ans);
    // reverse(ans.begin(), ans.end());
    for (auto a : ans)
    {
        cout << a << " ,";
    }
    return 0;
}