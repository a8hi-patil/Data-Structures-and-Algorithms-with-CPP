#include <iostream>
#include <cstdlib>
using namespace std;

bool isPalindrom(string str, int s, int e)
{

    while (s < e)
    {
        if (str[s++] != str[e--])
            return false;
    }
    return true;
}

string longestPalindrome(string s)
{
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i; j < s.length(); j++)
        {
            if (isPalindrom(s, i, j))
            {
                string sub = s.substr(i, j - i + 1);
                ans = sub.length() > ans.length() ? sub : ans;
            }
        }
    }

    return ans;
}
int main()
{
    system("cls");
    string s = "aacabdkacaa";
    cout << longestPalindrome(s);
    return 0;
}