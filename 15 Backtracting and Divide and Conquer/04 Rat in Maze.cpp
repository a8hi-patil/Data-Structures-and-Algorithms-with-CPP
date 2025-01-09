#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
bool isSafe(int newX, int newY, vector<vector<bool>> &visited, vector<vector<int>> &maze, int n)
{
    if (newX < 0 || newX > n - 1 || newY < 0 || newY > n - 1)
    {
        return false;
    }
    if (visited[newX][newY] == 1 || maze[newX][newY] == 0)
    {
        return false;
    }

    return true;
}

void findRoute(vector<vector<int>> &maze, int &n, vector<vector<bool>> &visited, vector<string> &ans, string path, int ratSx, int ratSy, int ratDx, int ratDy)
{
    if (ratSx == ratDx && ratSy == ratDy)
    {
        ans.push_back(path);
        return;
    }

    // Down D

    int newX = ratSx + 1;
    int newY = ratSy;

    if (isSafe(newX, newY, visited, maze, n))
    {
        visited[newX][newY] = 1;
        findRoute(maze, n, visited, ans, path + "D", newX, newY, ratDx, ratDy);
        visited[newX][newY] = 0;
    }

    // Up U
    newX = ratSx - 1;
    newY = ratSy;

    if (isSafe(newX, newY, visited, maze, n))
    {
        visited[newX][newY] = 1;
        findRoute(maze, n, visited, ans, path + "U", newX, newY, ratDx, ratDy);
        visited[newX][newY] = 0;
    }
    // Right R
    newX = ratSx;
    newY = ratSy + 1;

    if (isSafe(newX, newY, visited, maze, n))
    {
        visited[newX][newY] = 1;
        findRoute(maze, n, visited, ans, path + "R", newX, newY, ratDx, ratDy);
        visited[newX][newY] = 0;
    }
    // Left L
    newX = ratSx;
    newY = ratSy - 1;

    if (isSafe(newX, newY, visited, maze, n))
    {
        visited[newX][newY] = 1;
        findRoute(maze, n, visited, ans, path + "L", newX, newY, ratDx, ratDy);
        visited[newX][newY] = 0;
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
    string path = "";
    int ratSx = 0;
    int ratSy = 0;
    int ratDx = n - 1;
    int ratDy = n - 1;

    findRoute(maze, n, visited, ans, path, ratSx, ratSy, ratDx, ratDy);
    for (auto el : ans)
    {
        cout << el << endl;
    }
    cout << "ABC" << endl;
    return 0;
}