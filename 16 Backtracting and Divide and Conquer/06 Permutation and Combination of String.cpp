#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
void permutations(string &str, int i)
{
    if (i >= str.length())
    {
        cout << str << endl;
        return;
    }
    for (int j = i; j < str.length(); j++)
    {
        swap(str[i], str[j]);
        permutations(str, i + 1);
        swap(str[j], str[i]);
    }
}
int main()
{
    system("cls");
    string s = "ABC";
    permutations(s, 0);
    return 0;
}