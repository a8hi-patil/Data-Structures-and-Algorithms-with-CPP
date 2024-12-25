#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>

using namespace std;

int findSingleNumber(vector<int> arr)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]] = mp[arr[i]] + 1;
    }

    unordered_map<int, int>::iterator it;

    for (it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second == 1)
            return it->first;
    }
    return -1;
}

int main()
{
    system("cls");
    vector<int> arr = {4, 1, 2, 1, 2};
    int singleNumber = findSingleNumber(arr);
    cout << "Single Number in Array is " << singleNumber << endl;
    return 0;
}