#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
void merge(vector<int> &nums, int start, int mid, int end)
{
    int tl = end - start + 1;
    int gap = tl / 2 + tl % 2;

    while (gap > 0)
    {
        int i = start;
        int j = i + gap;
        while (j <= end)
        {
            if (nums[i] > nums[j])
            {
                swap(nums[i], nums[j]);
            }
            ++i;
            ++j;
        }
        gap = gap <= 1 ? 0 : ((gap / 2) + (gap % 2));
    }
}
void mergeSort(vector<int> &nums, int start, int end)
{
    if (start >= end)
        return;

    int mid = start + (end - start) / 2;

    mergeSort(nums, start, mid);
    mergeSort(nums, mid + 1, end);
    merge(nums, start, mid, end);
}

vector<int> sortArray(vector<int> &nums)
{

    mergeSort(nums, 0, nums.size() - 1);
    return nums;
}
int main()
{
    system("cls");
    vector<int> ans = {5, 2, 3, 1};
    sortArray(nums);
    for (auto a : nums)
    {
        cout << a << " ";
    }
    return 0;
}