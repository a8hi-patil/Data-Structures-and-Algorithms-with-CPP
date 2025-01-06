#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
int mincostTickets_helper(vector<int> &days, vector<int> &costs, int idx)
{
    if (idx >= days.size())
        return 0;

    int cost1 = costs[0] + mincostTickets_helper(days, costs, idx + 1);

    int passValidaity = days[idx] + 7 - 1;
    int j = idx;
    while (j < days.size() && days[j] <= passValidaity)
    {
        j++;
    }

    int cost7 = costs[1] + mincostTickets_helper(days, costs, j);

    passValidaity = days[idx] + 30 - 1;
    j = idx;
    while (j < days.size() && days[j] <= passValidaity)
    {
        j++;
    }
    int cost30 = costs[2] + mincostTickets_helper(days, costs, j);

    return min(cost1, min(cost7, cost30));
}
int mincostTickets(vector<int> &days, vector<int> &costs)
{
    return mincostTickets_helper(days, costs, 0);
}
int main()
{
    system("cls");
    vector<int> days = {1, 4, 6, 7, 8, 20}, costs = {2, 7, 15};
    cout << mincostTickets(days, costs);
    return 0;
}