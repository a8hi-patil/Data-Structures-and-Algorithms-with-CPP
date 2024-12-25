#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int missingNumber(vector<int> &arr)
{
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        ans ^= arr[i];
        ans ^= i;
    }
    return ans ^ arr.size();
}
int main()
{
    system("cls");
    vector<int> nums = {3, 0, 1};
    cout << missingNumber(nums);
    return 0;
}