#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
void printArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void sortColors(vector<int> &arr)
{
    int i = 0;
    int j = 0;
    int k = arr.size() - 1;

    while (j <= k)
    {
        if (arr[j] == 0)
        {
            swap(arr[i], arr[j]);
            i++;
            j++;
        }
        else if (arr[j] == 1)
        {
            j++;
        }
        else if (arr[j] == 2)
        {
            swap(arr[j], arr[k]);
            k--;
        }
    }
}
int main()
{
    system("cls");
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sortColors(nums);
    printArray(nums);
    return 0;
}