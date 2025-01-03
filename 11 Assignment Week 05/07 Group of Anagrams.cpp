#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{

    vector<vector<string>> ans;
    unordered_map<string, vector<string>> mp;

    for (int i = 0; i < strs.size(); i++)
    {
        string copy = strs[i];
        sort(copy.begin(), copy.end());
        mp[copy].push_back(strs[i]);
    }

    for (auto el : mp)
    {
        ans.push_back(el.second);
    }

    return ans;
}

int main()
{

    system("cls");
    vector<string> ip = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = groupAnagrams(ip);

    for (auto el : ans)
    {
        for (auto itm : el)
        {
            cout << itm << endl;
        }
        cout << "--" << endl;
    }

    return 0;
}