#include <iostream>
#include <cstdlib>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int convertToMins(string str)
{

    return stoi(str.substr(0, 2)) * 60 + stoi(str.substr(3, 2));
}
int findMinDifference(vector<string> &timePoints)
{

    // convert to time in minutes

    vector<int> mins;
    for (auto str : timePoints)
    {
        mins.push_back(convertToMins(str));
    }
    for (auto a : mins)
    {
        cout << a << ",";
    }
    cout << endl;

    int minDiff = INT_MAX;
    sort(mins.begin(), mins.end());
    for (int i = 1; i < mins.size(); i++)
    {
        minDiff = min(minDiff, mins[i] - mins[i - 1]);
    }
    // calculate last diff

    minDiff = min(minDiff, abs(mins[mins.size() - 1] - (mins[0] + 1440)));
    return minDiff;
}

int main()
{
    system("cls");
    vector<string> timePoints = {"00:00", "23:59", "00:00"};

    cout << findMinDifference(timePoints);
    return 0;
}