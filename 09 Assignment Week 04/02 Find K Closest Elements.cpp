#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start) / 2;
    int ans = end;
    while (start <= end)
    {
        if (arr[mid] >= x)
        {
            ans = mid;
            end = mid - 1;
        }
        else if (arr[mid] < x)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }

    int h = ans;
    int l = h - 1;
    while (k--)
    {
        if (l < 0)
        {
            h++;
        }
        else if (h >= arr.size())
        {
            l--;
        }
        else if (x - arr[l] > arr[h] - 1)
        {
            h++;
        }
        else
        {
            l--;
        }
    }

    return vector<int>(arr.begin() + l + 1, arr.begin() + h);
}

int main()
{
    system("cls");

    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4, x = 3;
    vector<int> ans = findClosestElements(arr, k, x);

    for (auto &&i : ans)
    {
        cout << i << " ";
    }

    return 0;
}