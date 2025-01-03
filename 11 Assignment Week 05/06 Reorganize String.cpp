#include <iostream>
#include <cstdlib>
#include <unordered_map>
using namespace std;
string reorganizeString(string s)
{

    int charHash[26] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        charHash[s[i] - 'a']++;
    }
    // find most frequent char and it frequency

    char mostFreqChar;
    int freq = INT_MIN;

    for (int i = 0; i < 26; i++)
    {
        if (charHash[i] > freq)
        {
            freq = charHash[i];
            mostFreqChar = i + 'a';
        }
    }

    // placing most frequent char
    int idx = 0;
    while (freq > 0 && idx < s.length())
    {
        s[idx] = mostFreqChar;
        idx += 2;
        freq--;
    }
    if (freq != 0)
        return "";

    charHash[mostFreqChar - 'a'] = 0;

    for (int i = 0; i < 26; i++)
    {
        while (charHash[i] > 0)
        {
            idx = idx >= s.length() ? 1 : idx;
            s[idx] = charHash[i] + 'a';
            idx += 2;
            charHash[i]--;
        }
    }
    return s;
}
int main()
{
    system("cls");
    string s = "aab";
    cout << reorganizeString(s);
    return 0;
}