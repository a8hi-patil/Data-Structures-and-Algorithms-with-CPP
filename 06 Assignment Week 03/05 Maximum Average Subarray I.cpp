#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
double findMaxAverage(vector<int> &arr, int k)
{
    double curSum = 0;
    double maxAvg = 0;

    // calculate first window

    for (int i = 0; i < k; i++)
    {
        curSum += arr[i];
    }
    maxAvg = curSum / k;

    int j = k;

    while (j < arr.size())
    {
        curSum += arr[j];
        curSum -= arr[j - k];
        maxAvg = max(maxAvg, curSum / k);

        j++;
    }
    return maxAvg;
}
int main()
{
    system("cls");
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    cout << "Max sum = " << findMaxAverage(nums, k);
    return 0;
}