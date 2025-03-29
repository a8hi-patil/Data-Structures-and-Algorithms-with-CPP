#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <unordered_map>
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
        }
        else
        {
            this->childs[src].push_back(des);
            this->childs[des].push_back(src);
        }
    }

    void printEdges(int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << " ->";
            for (auto ch : this->childs[i])
            {
                cout << ch << " ,";
            }
            cout << endl;
        }
    }
    void findShortestPath(int src, int des)
    {
        cout << endl;
        unordered_map<int, bool> vis;
        unordered_map<int, int> pMap;
        queue<int> q;

        q.push(src);
        vis[src] = true;
        pMap[src] = -1;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            for (auto chld : this->childs[front])
            {
                if (!vis[chld])
                {
                    vis[chld] = true;
                    pMap[chld] = front;
                    q.push(chld);
                }
            }
        }
        vector<int> path;
        int node = des;
        while (node != -1)
        {
            path.push_back(node);
            node = pMap[node];
        }
        cout << "Shotest Path from " << src << " to " << des << " is : " << endl;
        for (int i = path.size() - 1; i >= 0; i--)
        {
            if (i == 0)
            {
                cout << path[i];
                return;
            }
            cout << path[i] << "->";
        }
    }
};
int main()
{
    system("cls");
    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    // g.addEdge(2, 3, 0);
    g.addEdge(2, 4, 0);
    g.addEdge(4, 5, 0);
    g.addEdge(5, 3, 0);
    g.printEdges(6);

    int src = 0;
    int des = 3;
    g.findShortestPath(src, des);
    return 0;
}