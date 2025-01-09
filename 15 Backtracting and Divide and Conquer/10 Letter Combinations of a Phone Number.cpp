#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <vector>
using namespace std;

void solve(vector<string> &ans, string digits, unordered_map<char, string> &mp, int i, string op)
{
    if (i >= digits.length())
    {
        ans.push_back(op);
        return;
    }
    char digit = digits[i];
    string mappedString = mp[digit];

    for (int j = 0; j < mappedString.length(); j++)
    {
        op.push_back(mappedString[j]);
        solve(ans, digits, mp, i + 1, op);
        op.pop_back();
    }
}
void letterCombinations(vector<string> &ans, string digits, unordered_map<char, string> &mp, int i, string op)
{
    solve(ans, digits, mp, i, op);
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
    int i = 0;
    vector<string> ans;
    string output = "";
    letterCombinations(ans, digits, mp, i, output);
    for (auto a : ans)
    {
        cout << a << endl;
    }

    return 0;
}