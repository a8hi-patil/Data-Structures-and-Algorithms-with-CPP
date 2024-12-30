#include <iostream>
#include <cstdlib>
#include <unordered_map>
using namespace std;

string decodeTheMessage(string message, string key)
{
    unordered_map<char, char> mp;
    char start = 'a';
    mp[' '] = ' ';
    for (int i = 0; i < key.length(); i++)
    {
        if (!(mp.find(key[i]) != mp.end()))
        {
            mp[key[i]] = start++;
            continue;
        }
    }

    string ans = "";
    for (int i = 0; i < message.length(); i++)
    {

        ans.push_back(mp[message[i]]);
    }
    return ans;
}
int main()
{
    system("cls");
    string message = "vkbs bs t suepuv";
    string s = "the quick brown fox jumps over the lazy dog";
    string decodedMessage = decodeTheMessage(message, s);
    cout << "Decoded message from code :: " << message << " is :: " << decodedMessage << endl;
    return 0;
}