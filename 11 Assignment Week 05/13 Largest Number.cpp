#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <bits/stdc++.h>
using namespace std;

bool customComparator(string a, string b)
{
    return a + b > b + a;
}

string largestNumber(vector<int> &nums)
{
    vector<string> temp;
    for (auto num : nums)
    {
        temp.push_back(to_string(num));
    }
    sort(temp.begin(), temp.end(), customComparator);

    if (temp[0][0] == '0')
        return "0";
    string ans = "";

    for (auto str : temp)
    {
        ans += str;
    }
    return ans;
}
int main()
{
    system("cls");

    vector<int> nums = {3, 30, 34, 5, 9};
    string op = "9534330";

    cout << (largestNumber(nums) == op);
    return 0;
}