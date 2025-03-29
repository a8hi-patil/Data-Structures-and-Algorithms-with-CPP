#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>>
        adjList;
    void addEdge(int origin, int dest, int weight, bool direction)
    {
        // true single direction origin to destination
        if (direction)
        {
            this->adjList[origin].push_back({dest, weight});
        }
        else
        {
            // false bidirectional
            this->adjList[origin].push_back({dest, weight});
            this->adjList[dest].push_back({origin, weight});
        }
    }
    void printAdjList(int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Key : " << i << " ->";
            for (auto e : adjList[i])
            {
                cout << "{ " << e.first << ", " << e.second << " },";
            }
            cout << endl;
        }
        cout << endl;
    }
    void BSFTraversal(int src)
    {
        queue<int> q;
        unordered_map<int, bool> vis;
        q.push(src);
        vis[src] = true;
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            cout << front << ", ";
            for (auto el : adjList[front])
            {
                if (!vis[el.first])
                {
                    q.push(el.first);
                    vis[el.first] = true;
                }
            }
        }
    }
};
int main()
{
    system("cls");
    Graph g;
    g.addEdge(0, 3, 9, 1);
    g.addEdge(0, 5, 9, 1);
    g.addEdge(0, 2, 9, 1);
    g.addEdge(2, 5, 9, 1);
    g.addEdge(3, 5, 9, 1);
    g.addEdge(5, 4, 8, 1);
    g.addEdge(5, 6, 7, 1);
    g.addEdge(4, 1, 6, 1);
    g.addEdge(6, 1, 6, 1);
    g.printAdjList(7);
    g.BSFTraversal(0);
    return 0;
}