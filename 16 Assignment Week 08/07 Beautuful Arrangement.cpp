#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

void solve2(vector<int> &nums, int &c, int cn, int n)
{
    if (cn == n + 1)
    {
        c++;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (nums[i] == 0 && (cn % i == 0 || i % cn == 0))
        {
            nums[i] = cn;
            solve2(nums, c, cn + 1, n);
            nums[i] = 0;
        }
    }
}

int main()
{
    system("cls");
    vector<int> nums = {1, 2, 3};
    vector<int> nums2(nums.size() + 1);
    int c = 0;
    // solve(nums, 0, c);
    solve2(nums2, c, 1, 3);
    cout << c;
    return 0;
}