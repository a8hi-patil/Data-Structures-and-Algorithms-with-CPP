#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
int maxSum(vector<int> &nums, int start, int end)
{
    if (start == end)
    {
        return nums[start];
    }
    int LeftSum = INT_MIN;
    int RightSum = INT_MIN;

    int mid = start + (end - start) / 2;
    int maxLeft = maxSum(nums, start, mid);
    int maxRight = maxSum(nums, mid + 1, end);

    int lTemp = 0;
    for (int i = mid; i >= start; i--)
    {
        lTemp += nums[i];
        if (lTemp > LeftSum)
        {
            LeftSum = lTemp;
        }
    }
    int rTemp = 0;
    for (int i = mid + 1; i <= end; i++)
    {
        rTemp += nums[i];
        if (rTemp > RightSum)
        {
            RightSum = rTemp;
        }
    }
    int crossSum = LeftSum + RightSum;
    return max(crossSum, max(maxLeft, maxRight));
}
int maxSubArray(vector<int> &nums)
{

    return maxSum(nums, 0, nums.size() - 1);
}

int kaden(vector<int> &nums)
{
    int sum = 0;
    int maxi = nums[0];

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        maxi = max(sum, maxi);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxi;
}
int main()
{
    system("cls");
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(nums) << endl;
    cout << kaden(nums);
    return 0;
}