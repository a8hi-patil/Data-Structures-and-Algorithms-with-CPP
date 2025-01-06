// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void add(string &a, int endA, string &b, int endB, int carry, string &ans)
{
    if (endA < 0 && endB < 0)
    {
        if (carry)
        {
            ans.push_back(carry + '0');
        }
        return;
    }

    int n1 = endA < 0 ? 0 : (a[endA] - '0');
    int n2 = endB < 0 ? 0 : (b[endB] - '0');
    int sum = n1 + n2 + carry;
    int digit = sum % 10;
    carry = sum / 10;
    add(a, endA - 1, b, endB - 1, carry, ans);
    ans.push_back(digit + '0');
}

int main()
{

    string num1 = "92", num2 = "121";
    string ans = "";
    add(num1, num1.length() - 1, num2, num2.length() - 1, 0, ans);

    cout << ans << endl;
    // reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;
}