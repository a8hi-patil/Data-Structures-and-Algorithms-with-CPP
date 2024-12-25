#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &arr)
{

    int top = 0;
    int bottom = arr.size() - 1;
    int left = 0;
    int right = arr[0].size() - 1;
    vector<int> ans;
    int m = arr.size();
    int n = arr[0].size();
    int totalElements = m * n;

    while (totalElements)
    {
        // top row -> left to right

        for (int i = left; i <= right && totalElements > 0; i++)
        {
            ans.push_back(arr[top][i]);
            totalElements--;
        }
        top++;

        // right col -> top to botton
        for (int i = top; i <= bottom && totalElements > 0; i++)
        {
            ans.push_back(arr[i][right]);
            totalElements--;
        }
        right--;

        // bottom row -> right to left

        for (int i = right; i >= left && totalElements > 0; i--)
        {
            ans.push_back(arr[bottom][i]);
            totalElements--;
        }
        bottom--;

        // left col -> bottom to top

        for (int i = bottom; i >= top && totalElements > 0; i--)
        {
            ans.push_back(arr[i][left]);
            totalElements--;
        }
        left++;
    }
    return ans;
}
int main()
{
    system("cls");

    vector<vector<int>> nums = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    vector<int> nu = spiralOrder(nums);
    for (auto i : nu)
        cout << i << ", ";

    return 0;
}