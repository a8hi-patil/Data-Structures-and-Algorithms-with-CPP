#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <limits>
using namespace std;
int calBeauty(unordered_map<char, int> &mp)
{
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for (auto el : mp)
    {
        maxi = max(maxi, el.second);
        mini = min(mini, el.second);
    }

    return maxi - mini;
}
int beautySum(string s)
{
    int ans = 0;
    unordered_map<char, int> mp;
    for (int i = 0; i < s.length(); i++)
    {
        mp.clear();
        for (int j = i; j < s.length(); j++)
        {
            mp[s[j]]++;
            ans += calBeauty(mp);
        }
    }
    return ans;
}
int main()
{
    system("cls");
    string s = "aabcb";
    int ans = beautySum(s);
    cout << "Sum of beauty of " << s << " string is " << ans << endl;
    return 0;
}