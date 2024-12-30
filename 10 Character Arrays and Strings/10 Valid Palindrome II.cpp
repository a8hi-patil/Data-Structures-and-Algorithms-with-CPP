#include <iostream>
#include <cstdlib>
using namespace std;
bool val(string s, int st, int end)
{
    while (st <= end)
    {
        if (s[st] != s[end])
        {
            return false;
        }
        st++;
        end--;
    }
    return true;
}
bool checkValindPalindrom(string s)
{
    int start = 0;
    int end = s.length() - 1;
    bool isSkipped = false;

    while (start <= end)
    {
        if (s[start] != s[end])
        {

            return val(s, start + 1, end) || val(s, start, end - 1);
        }

        start++;
        end--;
    }

    return true;
}
int main()
{
    system("cls");
    string s = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";

    // s = "upuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupucu";

    cout
        << checkValindPalindrom(s);
    return 0;
}