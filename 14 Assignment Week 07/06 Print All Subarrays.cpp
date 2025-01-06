#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

void printArray(vector<int> &nums, int start, int end)
{
    if (start >= nums.size())
    {
        return;
    }
    if (end >= nums.size())
    {
        printArray(nums, start + 1, start + 1);
        return;
    }
    for (int i = start; i <= end; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    printArray(nums, start, end + 1);
}

int main()
{
    system("cls");

    vector<int> nums = {1, 2, 3, 4};

    printArray(nums, 0, 0);

    return 0;
}