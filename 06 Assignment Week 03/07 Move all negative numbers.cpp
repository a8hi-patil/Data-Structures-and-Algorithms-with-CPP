#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void shuffle(vector<int> &arr)
{
    int i = 0;
    int j = arr.size() - 1;

    while (i <= j)
    {
        if (arr[i] > 0 && arr[j] < 0)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        else if (arr[i] < 0)
        {
            i++;
        }
        else if (arr[j] > 0)
        {
            j--;
        }
    }
}
int main()
{
    vector<int> arr = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    shuffle(arr);
    for (int e : arr)
        cout << e << " ";
}