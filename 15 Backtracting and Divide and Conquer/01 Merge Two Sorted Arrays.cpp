#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
void mergeTwoArrays(vector<int> &a, vector<int> &b, vector<int> &ans)
{
    int sizeA = a.size() - 1;
    int sizeB = b.size() - 1;
    int startA = 0;
    int startB = 0;

    while (startA <= sizeA && startB <= sizeB)
    {
        if (a[startA] < b[startB])
        {
            ans.push_back(a[startA]);
            startA++;
        }
        else
        {
            ans.push_back(b[startB]);
            startB++;
        }
    }
    while (startA <= sizeA)
    {
        ans.push_back(a[startA]);
        startA++;
    }
    while (startB <= sizeB)
    {
        ans.push_back(b[startB]);
        startB++;
    }
}
int main()
{
    system("cls");
    vector<int> a = {20, 40, 60, 80, 90, 100};
    vector<int> b = {10, 30, 50, 70};
    vector<int> ans;
    mergeTwoArrays(a, b, ans);
    for (auto num : ans)
    {
        cout << num << " ";
    }
    return 0;
}