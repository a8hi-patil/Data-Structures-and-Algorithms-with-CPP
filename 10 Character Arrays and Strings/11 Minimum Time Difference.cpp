#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <vector>
#include <limits>
using namespace std;

int calMins(string str)
{
    return stoi(str.substr(0, 2)) * 60 + stoi(str.substr(3, 5));
}
void convertStringTimeToTimeArray(vector<string> &arr, vector<int> &mins)
{

    for (int i = 0; i < arr.size(); i++)
    {
        mins.push_back(calMins(arr[i]));
    }
}

int findMinimumTimeDiffrence(vector<int> &mins)
{
    sort(mins.begin(), mins.end());
    int diff = INT_MAX;

    for (int i = 1; i < mins.size(); i++)
    {
        diff = min(diff, (mins[i] - mins[i - 1]));
    }

    diff = min(diff, abs(mins[mins.size() - 1] - (mins[0] + 1440)));
    for (auto a : mins)
    {
        cout << a << " ";
    }
    return abs(diff);
}
int main()
{
    system("cls");
    vector<string> timePoints = {"00:00", "23:59", "00:00"};
    vector<int> timeInMinutes;
    convertStringTimeToTimeArray(timePoints, timeInMinutes);
    cout << findMinimumTimeDiffrence(timeInMinutes);
    return 0;
}