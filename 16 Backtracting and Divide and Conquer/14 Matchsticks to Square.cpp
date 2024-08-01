#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
int sum(vector<int> &matchstick)
{
    int sum = 0;
    for (int i = 0; i < matchstick.size(); i++)
    {
        sum += matchstick[i];
    }
    return sum;
}
bool solve(vector<int> &matchsticks, vector<int> &sides, int i)
{
    if (i == matchsticks.size())
    {
        return sides[0] == 0 && sides[1] == 0 && sides[2] == 0 && sides[3] == 0;
    }
    bool ans = false;
    for (int j = 0; j < sides.size(); j++)
    {
        if (matchsticks[i] <= sides[j])
        {
            sides[j] -= matchsticks[i];
            ans = ans || solve(matchsticks, sides, i + 1);
            sides[j] += matchsticks[i];
        }
    }
    return ans;
}
bool makesquare(vector<int> &matchsticks)
{
    if (matchsticks.size() < 4)
    {
        return false;
    }
    int total = sum(matchsticks);
    if (total % 4 != 0)
    {
        return false;
    }
    int side = total / 4;
    vector<int> sides(4, side);
    return solve(matchsticks, sides, 0);
}
int main()
{
    system("cls");
    vector<int> matchsticks = {1, 1, 2, 2, 2};
    cout << makesquare(matchsticks) << endl;
    return 0;
}