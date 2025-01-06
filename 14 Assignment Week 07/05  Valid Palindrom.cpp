#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
bool checkpalindrom(string str, int start, int end)
{
    if (start > end)
    {
        return true;
    }
    if (str[start] != str[end])
    {
        return false;
    }
    return checkpalindrom(str, start + 1, end - 1);
}
void test(bool ans, bool expected)
{
    if (ans == expected)
    {

        cout << "Passed :" << endl;
        if (ans)
        {
            cout << "Palindrom" << endl;
        }
        else
        {
            cout << "Not Palindrom" << endl;
        }
    }
    else
    {
        cout << "Failed" << endl;
    }
}
int main()
{
    system("cls");

    vector<string> ip = {"nitin", "amol"};
    vector<bool> op = {true, false};

    for (int i = 0; i < ip.size(); i++)
    {
        test(checkpalindrom(ip[i], 0, ip[i].length() - 1), op[i]);
    }

    return 0;
}