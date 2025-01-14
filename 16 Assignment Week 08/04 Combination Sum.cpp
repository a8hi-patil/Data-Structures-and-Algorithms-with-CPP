#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void solve(vector<vector<int>> &ans, vector<int> temp, vector<int> &candidates, int target, int start)
{
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }
    if (target < 0)
    {
        return;
    }
    for (int i = start; i < candidates.size(); i++)
    {
        temp.push_back(candidates[i]);
        solve(ans, temp, candidates, target - candidates[i], i);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
    solve(ans, temp, candidates, target, 0);
    return ans;
}
int main()
{
    system("cls");
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> ans = combinationSum(candidates, target);

    for (auto el : ans)
    {
        for (auto x : el)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}