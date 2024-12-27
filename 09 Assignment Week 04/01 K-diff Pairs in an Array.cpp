#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
int findPairs(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());

    // 1 1 3 4 5
    int i = 0;
    int j = i + 1;
    int counter = 0;
    while (j < arr.size())
    {
        int res = arr[j] - arr[i];
        cout << "j : " << arr[j] << " i " << arr[i] << endl;
        cout << "res : " << res << endl;
        if (res == k)
        {
            counter++;
            j++;
            i++;
        }
        else if (res < k)
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    return counter;
}
int main()
{
    system("cls");
    vector<int> nums = {1, 3, 1, 5, 4};
    int k = 0;
    cout << "Count : " << findPairs(nums, k);
    return 0;
}