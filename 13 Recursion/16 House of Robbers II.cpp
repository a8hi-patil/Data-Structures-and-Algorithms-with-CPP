#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
int steal(vector<int> &nums, int start, int end, int money)
{
    if (start > end)
    {
        return 0;
    }
    return max(nums[start] + steal(nums, start + 2, end, money + nums[start]), steal(nums, start + 1, end, money));
}
int rob(vector<int> &nums)
{
    return max(steal(nums, 0, nums.size() - 2, 0), steal(nums, 1, nums.size() - 1, 0));
}
int main()
{
    system("cls");
    vector<int> nums = {1, 2, 3};
    int op = 12;
    cout << rob(nums) << endl;
    return 0;
}