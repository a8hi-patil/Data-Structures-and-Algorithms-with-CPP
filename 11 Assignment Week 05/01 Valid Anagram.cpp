#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
bool isAnagram1(string &s, string &t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}
bool isAnagram2(string &s, string &t)
{
    if (s.length() != t.length())
    {
        return false;
    }
    unordered_map<char, int> sp;
    unordered_map<char, int> tp;
    for (int i = 0; i < s.length(); i++)
    {
        sp[s[i]]++;
        tp[t[i]]++;
    }
    for (auto p : sp)
    {
        if (tp[p.first] != p.second)
        {
            return false;
        }
    }
    return true;
}
bool isAnagram(string &s, string &t)
{
    int table[256] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        table[s[i]]++;
    }
    for (int i = 0; i < t.length(); i++)
    {
        table[t[i]]--;
        if (table[t[i]] < 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    system("cls");
    string s = "abhi", t = "ihab";
    cout << isAnagram(s, t);
    return 0;
}