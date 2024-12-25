#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

vector<int> fact(int n)
{
    vector<int> ans;
    ans.push_back(1);

    int carry = 0;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < ans.size(); j++)
        {
            int mul = ans[j] * i + carry;
            ans[j] = mul % 10;
            carry = mul / 10;
        }
        while (carry)
        {
            ans.push_back(carry % 10);
            carry /= 10;
        }
        carry = 0;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    system("cls");
    int n = 50;
    vector<int> ans = fact(n);

    for (int a : ans)
    {
        cout << a;
    }
    return 0;
}