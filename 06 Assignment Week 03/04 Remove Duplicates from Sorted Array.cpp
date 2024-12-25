#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int removeDuplicates(vector<int> &arr)
{
    int idx = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[idx] != arr[i])
        {
            idx++;
            arr[idx] = arr[i];
        }
        }

    return ++idx;
}
int main()
{
    system("cls");
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << removeDuplicates(nums) << endl;

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}