#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
void solve(vector<string> &ans, string digits, unordered_map<char, string> mp, int i, string output)
{
    if (i >= digits.length())
    {
        ans.push_back(output);
        return;
    }
    char digit = digits[i];
    string mappedString = mp[digit];

    for (int j = 0; j < mappedString.length(); j++)
    {
        output.push_back(mappedString[j]);
        solve(ans, digits, mp, i + 1, output);
        output.pop_back();
    }
}

vector<string> letterCombinations(vector<string> &ans, string digits, unordered_map<char, string> mp, int i, string output)
{
    solve(ans, digits, mp, 0, output);
    return ans;
}
int main()
{
    system("cls");
    unordered_map<char, string> mp;
    mp['1'] = "";
    mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";
    mp['0'] = "";
    string digits = "23";
    char i = '0';
    vector<string> ans;
    string output = "";
    letterCombinations(ans, digits, mp, i, output);
    for (auto a : ans)
    {
        cout << a << endl;
    }

    return 0;
}