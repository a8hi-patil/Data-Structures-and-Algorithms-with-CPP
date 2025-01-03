#include <iostream>
#include <cstdlib>
using namespace std;

bool isEnglishChar(char c)
{
    return ((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a'));
}
string reverseOnlyLetters(string s)
{
    int start = 0;
    int end = s.length() - 1;

    while (start <= end)
    {
        if (!isEnglishChar(s[start]))
        {
            start++;
        }
        else if (!isEnglishChar(s[end]))
        {
            end--;
        }
        else
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
    return s;
}

bool test(string s, string t)
{
    return s == t;
}
int main()
{
    system("cls");
    string s = "a-bC-dEf-ghIj";
    string op = "j-Ih-gfE-dCba";
    cout << op << endl;
    cout << reverseOnlyLetters(s) << endl;
    cout << test(reverseOnlyLetters(s), op);
    return 0;
}