#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>
using namespace std;

bool isIsomorphic2(string s, string t)
{
    if (s.length() != t.length())
        return false;

    unordered_map<char, int> mp;
    unordered_map<char, int> mp2;

    int c = 0;
    int d = 0;
    string ans = "";
    string ans2 = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (mp.find(s[i]) != mp.end())
        {
            ans.push_back(mp[s[i]] + '0');
        }
        else
        {
            mp[s[i]] = c;
            ans.push_back(c + '0');
            c++;
        }
        if (mp2.find(t[i]) != mp2.end())
        {
            ans2.push_back(mp2[t[i]] + '0');
        }
        else
        {
            mp2[t[i]] = d;
            ans2.push_back(d + '0');
            d++;
        }
    }

    return ans == ans2;
}

bool isIsomorphic(string s, string t)
{
    if (s.length() != t.length())
        return false;

    int hash[256] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        hash[s[i]]++;
        cout << hash[s[i]] << "(-)" << endl;
    }
    for (int i = 0; i < t.length(); i++)
    {
        hash[t[i]]--;
        if (hash[t[i]] < 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    system("cls");
    vector<string> ips = {"egg", "foo", "paper"};
    vector<string> ops = {"add", "bar", "title"

    };

    for (int i = 0; i < ips.size(); i++)
    {
        cout << isIsomorphic(ips[i], ops[i]) << endl;
    }
    return 0;
}