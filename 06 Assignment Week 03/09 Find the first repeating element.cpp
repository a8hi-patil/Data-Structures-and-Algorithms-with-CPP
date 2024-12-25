#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;

int findFirstRepeatingNumber(vector<int> &arr)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < arr.size(); i++)
    {

        mp[arr[i]]++;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (mp[arr[i]] > 1)
            return i + 1;
    }

    return -1;
}
int main()
{
    system("cls");
    vector<int> nms = {6, 10, 5, 4, 9, 120, 4, 6, 10};
    cout << findFirstRepeatingNumber(nms);
    return 0;
}