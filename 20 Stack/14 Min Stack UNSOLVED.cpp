#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class MinStack
{
    vector<pair<int, int>> v;
    MinStack() {}
    void push(int val)
    {
        if (v.empty())
        {
            v.push_back({val, val});
        }
        else
        {
            v.push_back({val, v.back().second < val ? v.back().second : val});
        }
    }
    void pop()
    {
        v.pop_back()
    }
    void top()
    {
        return v.back().first;
    }

    void getMin()
    {
        return v.back().second;
    }
};
int main()
{
    system("cls");
    return 0;
}