#include <iostream>
#include <cstdlib>
using namespace std;

int expand(string &str, int s, int e)
{
    int c = 0;

    while (s >= 0 && e < str.length() && str[s] == str[e])
    {
        c++;
        s--;
        e++;
    }
    return c;
}

int calculatePalindromicSubstrings(string &s)
{
    int total = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int c = i;
        int c2 = i;
        int odd = expand(s, c, c2);
        int even = expand(s, c, c2 + 1);

        total = total + odd + even;
    }
    return total;
}
int main()
{
    system("cls");
    string s = "aaaa";
    int ans = calculatePalindromicSubstrings(s);
    cout << "Palindromic sub string are " << ans << " !";
    return 0;
}