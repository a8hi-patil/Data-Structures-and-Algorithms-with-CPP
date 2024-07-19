#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
bool isLocationSafe(vector<vector<bool>> &blocked, int newSrcx, int newSrcy, vector<vector<bool>> &visited)
{
    int n = blocked.size();
    if (newSrcx < 0 || newSrcx >= n || newSrcy < 0 || newSrcy >= n)
    {
        return false;
    }
    if (blocked[newSrcx][newSrcy] == 0 || visited[newSrcx][newSrcy] == 1)
    {
        return false;
    }
    return true;
}
bool findRoute(vector<vector<bool>> &blocked, int srcx, int srcy, int desx, int desy, vector<vector<bool>> &visited)
{
    if (srcx == desx && srcy == desy)
    {
        return true;
    }
    // UP
    int newSrcx = srcx - 1;
    int newSrcy = srcy;
    bool ans = false;
    if (isLocationSafe(blocked, newSrcx, newSrcy, visited))
    {
        visited[newSrcx][newSrcy] = 1;
        ans = findRoute(blocked, newSrcx, newSrcy, desx, desy, visited);
        visited[newSrcx][newSrcy] = 0;
    }
    if (ans)
        return true;
    // Down
    newSrcx = srcx + 1;
    newSrcy = srcy;
    if (isLocationSafe(blocked, newSrcx, newSrcy, visited))
    {
        visited[newSrcx][newSrcy] = 1;
        ans = findRoute(blocked, newSrcx, newSrcy, desx, desy, visited);
        visited[newSrcx][newSrcy] = 0;
    }
    if (ans)
        return true;
    // Right
    newSrcx = srcx;
    newSrcy = srcy + 1;
    if (isLocationSafe(blocked, newSrcx, newSrcy, visited))
    {
        visited[newSrcx][newSrcy] = 1;
        ans = findRoute(blocked, newSrcx, newSrcy, desx, desy, visited);
        visited[newSrcx][newSrcy] = 0;
    }
    if (ans)
        return true;
    // Left
    newSrcx = srcx;
    newSrcy = srcy - 1;
    if (isLocationSafe(blocked, newSrcx, newSrcy, visited))
    {
        visited[newSrcx][newSrcy] = 1;
        ans = findRoute(blocked, newSrcx, newSrcy, desx, desy, visited);
        visited[newSrcx][newSrcy] = 0;
    }
    if (ans)
    {

        return true;
    }
    else
    {
        return false;
    }
}

bool isEscapePossible(vector<vector<int>> &blocked, vector<int> &source, vector<int> &target)
{
    if (blocked.size() == 0)
    {
        return true;
    }
    vector<vector<bool>> grid(1000000, vector<bool>(100000, 1));
    int n = blocked.size();
    for (int i = 0; i < n; i++)
    {
        int x = blocked[i][0];
        int y = blocked[i][1];
        grid[x][y] = 0;
    }
    vector<vector<bool>> visited(1000000, vector<bool>(1000000, 0));
    int srcx = source[0];
    int srcy = source[1];
    int desx = target[0];
    int desy = target[1];

    return findRoute(grid, srcx, srcy, desx, desy, visited);
}
int main()
{
    system("cls");
    vector<vector<int>> blocked = {{691938, 300406}, {710196, 624190}, {858790, 609485}, {268029, 225806}, {200010, 188664}, {132599, 612099}, {329444, 633495}, {196657, 757958}, {628509, 883388}};
    vector<int> source = {655988, 180910};
    vector<int> target = {267728, 840949};
    bool ans = isEscapePossible(blocked, source, target);

    if (ans)
    {
        cout << "Escape Possible" << endl;
    }
    else
    {
        cout << "Escape not possible" << endl;
    }
    return 0;
}