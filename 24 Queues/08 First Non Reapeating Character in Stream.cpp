#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <queue>
using namespace std;
string solve(string A)
{
    unordered_map<char, int> freq;
    string ans = "";
    queue<char> q;

    for (int i = 0; i < A.length(); i++)
    {
        char ch = A[i];
        freq[ch]++;
        q.push(ch);
        while (!q.empty())
        {
            char frontEle = q.front();
            if (freq[frontEle] == 1)
            {
                ans.push_back(frontEle);
                break;
            }
            else
            {
                q.pop();
            }
        }
        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}
int main()
{
    system("cls");
    cout << solve("aabbc");
    return 0;
}