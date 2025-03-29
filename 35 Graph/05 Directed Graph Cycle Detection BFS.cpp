#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> childs;

    void addEdge(int src, int des, bool dir)
    {
        if (dir)
        {
            this->childs[src].push_back(des);
            this->childs[des].push_back(src);
        }
        else
        {
            this->childs[src].push_back(des);
        }
    }
    bool isCyclePresent(int src)
    {
        queue<int> q;
        q.push(src);
        unordered_map<int, bool> vis;
        vis[src] = true;
        unordered_map<int, int> pMap;
        pMap[src] = -1;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (auto el : this->childs[front])
            {
                if (!vis[el])
                {
                    vis[el] = true;
                    pMap[el] = front;
                    q.push(el);
                }
                else if (vis[el] && pMap[front] != el)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    system("cls");

    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(1, 0, 0);
    g.addEdge(1, 1, 0);
    // g.addEdge(3, 0, 0);

    cout << g.isCyclePresent(0);

    return 0;
}