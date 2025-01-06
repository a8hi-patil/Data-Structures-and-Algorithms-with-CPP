// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    string num1 = "1", num2 = "9";

    int numOne = num1.length() - 1;
    int numTwo = num2.length() - 1;
    string ans = "";
    int carry = 0;
    while (numOne >= 0 && numTwo >= 0)
    {

        int sum = (num1[numOne] - '0') + (num2[numTwo] - '0') + carry;
        int lastDigit = sum % 10;
        carry = sum / 10;
        char chartoPushed = lastDigit + '0';
        // cout<<lastDigit<<"D->"<<chartoPushed<<endl;
        ans.push_back(chartoPushed);
        numOne--;
        numTwo--;
    }
    while (numOne >= 0)
    {
        int sum = (num1[numOne] - '0') + carry;
        int lastDigit = sum % 10;
        carry = sum / 10;
        char chartoPushed = lastDigit + '0';
        // cout<<lastDigit<<"D->"<<chartoPushed<<endl;
        ans.push_back(chartoPushed);
        numOne--;
    }
    while (numTwo >= 0)
    {

        int sum = (num2[numTwo] - '0') + carry;
        int lastDigit = sum % 10;
        carry = sum / 10;
        char chartoPushed = lastDigit + '0';
        // cout<<lastDigit<<"D->"<<chartoPushed<<endl;
        ans.push_back(chartoPushed);

        numTwo--;
    }
    if (carry)
    {
        ans.push_back(carry + '0');
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;
}