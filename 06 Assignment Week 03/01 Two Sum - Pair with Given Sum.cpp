#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool twoSum(vector<int> &arr, int target)
{
    sort(arr.begin(), arr.end());
    int start = 0;
    int end = arr.size() - 1;

    while (start < end)
    {
        if (arr[start] + arr[end] > target)
        {
            end--;
        }
        else if (arr[start] + arr[end] < target)
        {
            start++;
        }
        else
        {
            return true;
        }
    }
    return false;
}
int main()
{
    system("cls");
    vector<int> arr = {1, 4, 45, 6, 10, 8};
    int target = 16;
    cout << twoSum(arr, target);
    return 0;
}