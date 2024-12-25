#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

vector<int> add(vector<int> &a, vector<int> &b)
{
    int sizeA = a.size() - 1;
    int sizeB = b.size() - 1;
    int sizeAns = sizeA > sizeB ? sizeA : sizeB;
    vector<int> ans(0, sizeAns + 1);

    int carry = 0;
    while (sizeA >= 0 && sizeB >= 0)
    {
        int sum = a[sizeA] + b[sizeB] + carry;
        carry = sum / 10;
        int digit = sum % 10;
        ans.push_back(digit);
        sizeA--;
        sizeB--;
    }
    while (sizeA >= 0)
    {
        int sum = a[sizeA] + carry;
        carry = sum / 10;
        int digit = sum % 10;
        ans.push_back(digit);
        sizeA--;
    }
    while (sizeB >= 0)
    {
        int sum = a[sizeB] + carry;
        carry = sum / 10;
        int digit = sum % 10;
        ans.push_back(digit);
        sizeB--;
    }
    if (carry)
    {
        ans.push_back(carry);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    system("cls");
    vector<int> a = {1, 2};
    vector<int> b = {2, 1};
    vector<int> ans = add(a, b);
    for (auto x : ans)
        cout << x << ",";
    return 0;
}