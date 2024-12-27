#include <iostream>
#include <vector>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

bool isPos(vector<int> &stalls, int k, int diff)
{
    int cows = 1;
    int pos = stalls[0];
    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - pos >= diff)
        {
            pos = stalls[i];
            cows++;
            if (cows == k)
            {
                return true;
            }
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{

    sort(stalls.begin(), stalls.end());
    int start = 0;
    int end = stalls[stalls.size() - 1];
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isPos(stalls, k, mid))
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}
int main()
{
    system("cls");
    vector<int> stalls = {1, 2, 4, 8, 9};
    int k = 3;
    cout << aggressiveCows(stalls, k);

    return 0;
}