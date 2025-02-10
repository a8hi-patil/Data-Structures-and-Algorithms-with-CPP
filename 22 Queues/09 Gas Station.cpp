#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
int main()
{
    system("cls");
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    int start = 0, less = 0, rem = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        if (rem + gas[i] < cost[i])
        {
            start = i + 1;
            less = less + rem + gas[i] - cost[i];
            rem = 0;
        }
        else
        {
            rem = rem + gas[i] - cost[i];
        }
    }
    if (rem + less >= 0)
        return start;

    return -1;
}