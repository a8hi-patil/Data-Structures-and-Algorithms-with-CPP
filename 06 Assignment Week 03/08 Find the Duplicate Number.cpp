#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int findDuplicate(vector<int> &arr)
{

    for (int i = 0; i < arr.size(); i++)
    {
        int idx = abs(arr[i]);
        if (arr[idx] < 0)
        {
            return idx;
        }
        else
        {
            arr[idx] *= -1;
        }
    }
    return -1;
}

int main()
{
    system("cls");
    vector<int> arr = {1, 3, 4, 2, 2};
    cout << findDuplicate(arr);
    return 0;
}