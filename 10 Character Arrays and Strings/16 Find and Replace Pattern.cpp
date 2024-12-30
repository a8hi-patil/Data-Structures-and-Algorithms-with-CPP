#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>
using namespace std;
string determinPattern(string a)
{
    unordered_map<char, int> mp;
    string ans = "";
    if (a.length() == 0)
    {
        return ans;
    }
    char prev = '#';
    int c = 0;
    for (int i = 0; i < a.length(); i++)
    {
        char cur = a[i];
        if (mp.find(cur) != mp.end())
        {
            ans.push_back(mp[cur] + '0');
        }
        else
        {
            ans.push_back(c + '0');
            mp[cur] = c;
            c++;
        }
    }
    return ans;
}
bool isMactching(string ms, string ps, int len)
{
    while (len--)
    {
        if (ps[len] != ms[len])
            return false;
    }
    return true;
}
vector<string> findAndReplacePattern(vector<string> &words, string pattern)
{
    string masterPattern = determinPattern(pattern);
    int len = masterPattern.length();
    vector<string> ans;
    for (int i = 0; i < words.size(); i++)
    {
        if (len == words[i].length())
        {

            if (isMactching(masterPattern, determinPattern(words[i]), len))
            {
                ans.push_back(words[i]);
            }
        }
    }
    return ans;
}
int main()
{
    system("cls");
    vector<string> words = {"abc", "deq", "mee", "aqq", "dkd", "ccc"};
    string pattern = "abb";
    vector<string> ans = findAndReplacePattern(words, pattern);
    for (auto s : ans)
    {
        cout << s << endl;
    }
    return 0;
}