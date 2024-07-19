#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
void permute(vector<int> &nums, vector<vector<int>> &ans, int i)
{
    if (i >= nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int j = i; j < nums.size(); j++)
    {
        swap(nums[i], nums[j]);
        permute(nums, ans, i + 1);
        swap(nums[j], nums[i]);
    }
}

int main()
{
    system("cls");
    vector<int> v = {1, 2, 3};
    vector<vector<int>> ans;
    permute(v, ans, 0);
    for (auto a : ans)
    {
        for (auto v : a)
        {
            cout << v << " ,";
        }
        cout << endl;
    }
    return 0;
}