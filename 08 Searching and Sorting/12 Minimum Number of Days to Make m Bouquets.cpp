#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

bool canWeMakeBouquets(vector<int> &arr, int m, int k, int day)
{

    int ful = 0;
    int buke = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= day)
        {
            ful++;
        }
        else
        {
            ful = 0;
        }
        if (ful == k)
        {
            buke++;
            ful == 0;
        }
        if (buke == m)
        {
            break;
        }
    }
    return m == buke;
}
int minDays(vector<int> &arr, int m, int k)
{
    int start = *min_element(arr.begin(), arr.end());
    int end = *max_element(arr.begin(), arr.end());
    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start <= end)
    {
        if (canWeMakeBouquets(arr, m, k, mid))
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
    vector<int> arr = {1, 10, 3, 10, 2};
    int m = 3, k = 1;
    cout << minDays(arr, m, k);
    return 0;
}