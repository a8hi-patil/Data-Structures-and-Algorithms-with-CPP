#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int steal(vector<int> &nums, int start, int money)
{
    if (start >= nums.size())
    {
        return money;
    }
    return max(
        steal(nums, start + 2, money + nums[start]),
        steal(nums, start + 1, money));
}

int rob(vector<int> &nums)
{
    return steal(nums, 0, 0);
}
int main()
{
    system("cls");

    vector<int> nums = {6, 2, 3, 6};
    int op = 12;
    cout << rob(nums) << endl;
    return 0;
}