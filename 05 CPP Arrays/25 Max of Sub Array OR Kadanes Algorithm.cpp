#include <iostream>
#include <cstdlib>
using namespace std;

int kadanesAlgorithm(int arr[], int size)
{
    int curSum = 0;
    int maxSum = 0;

    for (int i = 0; i < size; i++)
    {
        curSum = curSum + arr[i];
        maxSum = max(curSum, maxSum);
        if (curSum < 0)
            curSum = 0;
    }
    return maxSum;
}
int main()
{
    system("cls");
    int arr[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int maxSubArraySum = kadanesAlgorithm(arr, 9);
    cout << "Max sub array sum is " << maxSubArraySum << endl;
    return 0;
}