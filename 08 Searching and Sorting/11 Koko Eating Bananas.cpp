#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

bool kokoCanEat(vector<int> arr, int h, int banana)
{
    int hrs = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        hrs += ceil(arr[i] / double(banana));
    }
    return hrs <= h;
}
int findMinimumNumberOfBananas(vector<int> arr, int h)
{
    int start = 1;
    int end = *max_element(arr.begin(), arr.end());
    int mid = start + (end - start) / 2;
    int ans = -1;
    while (start <= end)
    {
        if (kokoCanEat(arr, h, mid))
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
    vector<int> arr = {3, 6, 7, 11};
    int h = 8;
    cout << "Koko can eat all bananas in " << h << " hours if she eats " << findMinimumNumberOfBananas(arr, h) << " bananas per hour." << endl;
    return 0;
}