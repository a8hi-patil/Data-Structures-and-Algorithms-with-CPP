#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
void printArray(vector<int> &ar)
{
    for (int i = 0; i < ar.size(); i++)
    {
        cout << ar[i] << ",";
    }
    cout << endl;
}
int findPivoteIndex(vector<int> &arr)
{
    vector<int> lsum(arr.size(), 0);
    vector<int> rsum(arr.size(), 0);

    for (int i = 0; i < arr.size(); i++)
    {
        if (i == 0)
        {
            lsum[i] = arr[i];
            rsum[arr.size() - i - 1] = arr[arr.size() - i - 1];
        }
        else
        {
            lsum[i] = arr[i] + lsum[i - 1];
            rsum[arr.size() - i - 1] = arr[arr.size() - i - 1] + rsum[arr.size() - i];
        }
    }
    for (int i = 0; i < lsum.size(); i++)
    {
        if (lsum[i] == rsum[i])
            return i;
    }
    return false;
}
int main()
{
    system("cls");
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    cout << findPivoteIndex(nums);
    return 0;
}