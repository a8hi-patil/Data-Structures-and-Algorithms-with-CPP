#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
bool isVowel(char ch)
{

    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}
string reverseVowels(string str)
{
    int s = 0;
    int e = str.length() - 1;

    while (s < e)
    {
        if (!isVowel(str[s]))
        {
            s++;
        }
        else if (!isVowel(str[e]))
        {
            e--;
        }
        else
        {
            swap(str[s++], str[e--]);
        }
    }
    return str;
}

void test(string ip, string op, string res)
{
    if (op == res)
    {
        cout << "Passed : Input " << ip << " Output " << res << endl;
    }
    else
    {
        cout << "Failed : Input " << ip << " Output " << res << " Expected " << op << endl;
    }
}

int main()
{
    system("cls");
    vector<string> ips = {"IceCreAm", "leetcode"};
    vector<string> ops = {"AceCreIm", "leotcede"};

    for (int i = 0; i < ips.size(); i++)
    {
        test(ips[i], ops[i], reverseVowels(ips[i]));
    }
    return 0;
}