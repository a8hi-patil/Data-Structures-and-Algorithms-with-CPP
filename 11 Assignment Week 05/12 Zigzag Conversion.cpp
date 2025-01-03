#include <iostream>
#include <cstdlib>
#include <vector>
#include <chrono>
using namespace std;

string convert(string s, int numRows)
{
    int itr = 0;
    int len = s.length();
    if (numRows == 0 || numRows == 1)
    {
        return s;
    }
    vector<string> ans(numRows, "");
    bool condition = true;
    int pendulam = 0;
    while (true)
    {
        cout << pendulam << endl;
        if (pendulam >= numRows - 1)
        {
            condition = false;
        }
        else if (pendulam <= 0)
        {
            condition = true;
        }

        if (condition)
        {
            ans[pendulam] += s[itr];
            pendulam++;
        }
        else
        {
            ans[pendulam] += s[itr];
            pendulam--;
        }

        itr++;
        if (itr >= len)
        {
            break;
        }
    }
    string finalAns = "";

    for (int i = 0; i < ans.size(); i++)
    {
        finalAns += ans[i];
    }
    return finalAns;
}
int main()
{
    system("cls");
    string s = "PAYPALISHIRING";
    int numRows = 3;
    string ans = "PAHNAPLSIIGYIR";
    auto start = chrono::high_resolution_clock::now();
    cout << (convert(s, numRows) == ans) << endl;
    auto end = chrono::high_resolution_clock::now();

    // Calculate the duration
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    // Output the duration
    cout << "Time taken: " << duration.count() << " microseconds" << endl;
}