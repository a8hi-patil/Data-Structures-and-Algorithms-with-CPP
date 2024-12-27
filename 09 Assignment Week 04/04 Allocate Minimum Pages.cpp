#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
bool canWeAssign(vector<int> &arr, int k, int maxPages)
{
    int currentPages = 0;
    int count = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] >= maxPages)
            return false;

        if (currentPages + arr[i] > maxPages)
        {
            count++;
            currentPages = arr[i];
            if (count > k)
                return false;
        }
        else
        {
            currentPages += arr[i];
        }
    }
    return true;
}
int maxPages(vector<int> &arr, int k)
{

    if (arr.size() < k)
        return -1;
    int start = 0;
    int end = accumulate(arr.begin(), arr.end(), 0);
    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start <= end)
    {
        if (canWeAssign(arr, k, mid))
        {
            cout << "Ans " << mid << endl;
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
    vector<int> arr = {12, 34, 67, 90};
    int k = 2;
    cout << maxPages(arr, k);
    return 0;
}