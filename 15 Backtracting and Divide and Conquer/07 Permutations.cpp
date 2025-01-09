#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

void calc(vector<int> &nums, vector<vector<int>> &ans, int idx)
{

    if (idx == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[i], nums[idx]);
        calc(nums, ans, idx + 1);
        swap(nums[i], nums[idx]);
    }
}

int main()
{
    system("cls");
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans;

    calc(nums, ans, 0);

    for (auto el : ans)
    {

        for (auto el1 : el)
        {
            cout << el1 << " ";
        }
        cout << endl;
    }

    return 0;
}