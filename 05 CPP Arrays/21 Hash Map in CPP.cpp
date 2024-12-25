#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, int> createMap()
{
    unordered_map<string, int> myMap;
    return myMap;
}

void initializeMap(vector<pair<string, int>> &arr, unordered_map<string, int> &mp)
{

    for (int i = 0; i < arr.size(); i++)
    {
        mp.insert(arr[i]);
    }
}

void printMap(unordered_map<string, int> &mp)
{
    unordered_map<string, int>::iterator it;

    for (it = mp.begin(); it != mp.end(); it++)
    {
        string key = it->first;
        int val = it->second;

        cout << key << " : " << val << endl;
    }
}

void remove(unordered_map<string, int> &mp, string key)
{
    mp.erase(key);
}

void findInMap(unordered_map<string, int> &mp, string key)
{
    if (mp.find(key) != mp.end())
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
}

int main()
{
    unordered_map<string, int> mp = createMap();
    vector<pair<string, int>> vc = {{"A", 65},
                                    {"B", 66},
                                    {"C", 67}};

    initializeMap(vc, mp);
    printMap(mp);
    findInMap(mp, "A");
    findInMap(mp, "X");
    remove(mp, "A");
    cout << "REMOVING" << endl;
    printMap(mp);

    return 0;
}