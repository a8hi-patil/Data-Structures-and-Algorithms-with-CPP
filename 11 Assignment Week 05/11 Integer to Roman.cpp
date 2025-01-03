#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

string intToRoman(int num)

{

    vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    vector<int> vals = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string ans = "";

    int i = 0;
    while (num)
    {
        while (num >= vals[i])
        {
            ans.append(symbols[i]);
            num -= vals[i];
        }
        i++;
    }
    return ans;
}
int main()
{
    system("cls");
    int num = 3749;
    cout << intToRoman(num);
    return 0;
}