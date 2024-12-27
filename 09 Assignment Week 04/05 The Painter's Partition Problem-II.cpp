#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
bool canWePaint(vector<int> &arr, int k, int minHrs)
{

    int curHrs = 0;
    int painters = 1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > minHrs)
            return false;

        if (curHrs + arr[i] > minHrs)
        {
            painters++;
            curHrs = arr[i];
            if (painters > k)
            {
                return false;
            }
        }
        else
        {
            curHrs += arr[i];
        }
    }
    return true;
}
int minTime(vector<int> &arr, int k)
{
    int start = 0;
    int end = accumulate(arr.begin(), arr.end(), 0);
    int mid = start + (end - start) / 2;
    int ans = -1;

    while (start <= end)
    {
        if (canWePaint(arr, k, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }

        mid = start + (end - start) / 2;
    }
    return ans;
}
int main()
{
    system("cls");
    vector<int> arr = {100, 200, 300, 400};
    int k = 1;
    cout << minTime(arr, k);
    return 0;
}