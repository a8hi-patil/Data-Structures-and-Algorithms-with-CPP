#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

void solve(vector<vector<int>> &ans, vector<int> temp,
           vector<int> &candidates, int target, int start)
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
        if (i > start && candidates[i] == candidates[i - 1])
        {
            continue;
        }
        temp.push_back(candidates[i]);
        solve(ans, temp, candidates, target - candidates[i], i + 1);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> temp;
    solve(ans, temp, candidates, target, 0);

    return ans;
}

int main()
{
    system("cls");
    vector<vector<int>> ans = combinationSum2(candidates, target);

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