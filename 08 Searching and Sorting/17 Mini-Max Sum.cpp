#include <iostream>
#include <cstdlib>
#include <vector>
#include <limits>
using namespace std;
vector<int> find(vector<int> &arr)
{

    vector<int> ans;
    int mini = INT_MAX;
    int maxi = INT_MIN;
    int start = 0;
    int end = arr.size() - 2;

    int sum = 0;

    // calculate first sum

    for (int i = 0; i <= end; i++)
    {
        sum += arr[i];
    }
    mini = sum;
    maxi = sum;
    int i = start;
    int j = end;
    start++;
    end++;
    while (start < arr.size())
    {
        sum = sum - arr[i];
        sum = sum + arr[(j + 1) % arr.size()];
        mini = min(mini, sum);
        maxi = max(maxi, sum);
        i++;
        j++;
        start++;
    }
    cout << "Max " << maxi << " Mini " << mini << endl;
    return ans;
}
int main()
{
    system("cls");
    vector<int> nums = {1, 3, 5, 7, 9};
    vector<int> ans = find(nums);
    for (int a : ans)
    {
        cout << a << " ,";
    }
    return 0;
}