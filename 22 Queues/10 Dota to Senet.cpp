#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;
string predictPartyVictory(string s)
{
    queue<int> d;
    queue<int> r;
    int pos = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'D')
        {
            d.push(pos++);
        }
        else
        {
            r.push(pos++);
        }
    }
    while (!r.empty() && !d.empty())
    {
        if (d.front() < r.front())
        {
            d.pop();
            r.pop();
            d.push(pos++);
        }
        else
        {
            r.pop();
            d.pop();
            r.push(pos++);
        }
    }
    return d.empty() ? "Radient" : "Dire";
}
int main()
{
    system("cls");
    string senate = "RDDRDRDDRDR";
    cout << predictPartyVictory(senate);
    return 0;
}