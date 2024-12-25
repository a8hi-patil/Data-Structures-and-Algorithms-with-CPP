#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

pair<int, int> twoSum(int arr[], int size, int target)
{
    sort(arr, arr + size);
    int start = 0, end = size - 1;
    while (start <= end)
    {
        int res = arr[start] + arr[end];
        if (res < target)
        {
            start++;
        }
        else if (res > target)
        {
            end--;
        }
        else
        {
            return {start, end};
        }
    }
    return {-1, -1};
}
int main()
{
    system("cls");
    int arr[5] = {10, 20, 30, 40, 50};
    int size = 5;
    int target = 110;
    pair<int, int> res;
    res = twoSum(arr, size, target);

    if (res.first == -1)
    {
        cout << "NO PAIR FOUND";
    }
    else
    {
        cout << "Paire is " << res.first << " and " << res.second << endl;
    }

    return 0;
}