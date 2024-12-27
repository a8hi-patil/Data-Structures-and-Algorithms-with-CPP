#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int bs(vector<int> &arr, int start, int end, int target)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid + 1;
        }
    }
    return -1;
}
int expSearch(vector<int> &arr, int target)
{

    if (arr[0] == target)
    {
        return 0;
    }
    int i = 1;
    while (i < arr.size() && arr[i] < target)
    {
        i *= 2;
    }
    int n = arr.size();
    return bs(arr, (i / 2), min(i, n - 1), target);
}

int main()
{
    system("cls");
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int target = 5;
    cout << expSearch(arr, target) << endl;
    return 0;
}