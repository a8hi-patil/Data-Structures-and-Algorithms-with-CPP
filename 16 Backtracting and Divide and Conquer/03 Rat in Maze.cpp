#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

bool isLocationSafe(vector<vector<int>> maze, int n, vector<vector<bool>> visited, int newSrcx, int newSrcy)
{
    if (newSrcx < 0 || newSrcx >= n || newSrcy < 0 || newSrcy >= n)
    {
        return false;
    }
    if (maze[newSrcx][newSrcy] == 0 || visited[newSrcx][newSrcy] == 1)
    {
        return false;
    }
    return true;
}

void findRoutes(vector<vector<int>> maze, int n, vector<vector<bool>> &visited, int srcx, int srcy, int desx, int desy, string output, vector<string> &ans)
{
    // Base case
    if (srcx == desx && srcy == desy)
    {
        ans.push_back(output);
        return;
    }
    // Move Up i--, j
    int newSrcy = srcy;
    int newSrcx = srcx - 1;
    if (isLocationSafe(maze, n, visited, newSrcx, newSrcy))
    {
        visited[newSrcx][newSrcy] = 1;
        findRoutes(maze, n, visited, newSrcx, newSrcy, desx, desy, output + "U", ans);
        visited[newSrcx][newSrcy] = 0;
    }
    // Move Down i++ , j
    newSrcy = srcy;
    newSrcx = srcx + 1;
    if (isLocationSafe(maze, n, visited, newSrcx, newSrcy))
    {
        visited[newSrcx][newSrcy] = 1;
        findRoutes(maze, n, visited, newSrcx, newSrcy, desx, desy, output + "D", ans);
        visited[newSrcx][newSrcy] = 0;
    }
    // Move Left i , j--
    newSrcy = srcy - 1;
    newSrcx = srcx;
    if (isLocationSafe(maze, n, visited, newSrcx, newSrcy))
    {
        visited[newSrcx][newSrcy] = 1;
        findRoutes(maze, n, visited, newSrcx, newSrcy, desx, desy, output + "L", ans);
        visited[newSrcx][newSrcy] = 0;
    }
    // Move Right i , j++
    newSrcy = srcy + 1;
    newSrcx = srcx;
    if (isLocationSafe(maze, n, visited, newSrcx, newSrcy))
    {
        visited[newSrcx][newSrcy] = 1;
        findRoutes(maze, n, visited, newSrcx, newSrcy, desx, desy, output + "R", ans);
        visited[newSrcx][newSrcy] = 0;
    }
}
int main()
{
    system("cls");
    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};
    int n = maze.size();
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    vector<string> ans;
    int srcx = 0;
    int srcy = 0;
    int desx = n - 1;
    int desy = n - 1;
    visited[srcx][srcy] = 1;
    string output = "";

    findRoutes(maze, n, visited, srcx, srcy, desx, desy, output, ans);

    for (auto a : ans)
    {
        cout << a << endl;
    }

    return 0;
}