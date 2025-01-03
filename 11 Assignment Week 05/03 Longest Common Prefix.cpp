#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
string longestCommonPrefix(vector<string> &strs)
{

    string ans = "";
    int c = 0;
    while (true)
    {
        if (!(c < strs[0].length()))
        {
            return ans;
        }
        char curC = strs[0][c];
        for (int i = 0; i < strs.size(); i++)
        {
            if (curC != strs[i][c])
            {
                return ans;
            }
        }
        ans.push_back(curC);
        c++;
    }
    return ans;
}
int main()
{
    system("cls");
    vector<string> strs = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(strs);
    return 0;
}