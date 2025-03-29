#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <list>
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
    void DFDTraversal_helper(int src, unordered_map<int, bool> &vis)
    {
        if (vis[src])
            return;
        cout << src << " ";
        vis[src] = true;
        for (auto el : this->childs[src])
        {
            DFDTraversal_helper(el, vis);
        }
    }
    void DFDTraversal(int src)
    {
        unordered_map<int, bool> vis;
        DFDTraversal_helper(src, vis);
    }
};

int main()
{
    system("cls");

    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(1, 5, 0);
    g.addEdge(5, 4, 0);
    g.addEdge(3, 4, 0);
    g.addEdge(4, 6, 0);
    g.addEdge(4, 8, 0);
    g.addEdge(8, 7, 0);
    g.DFDTraversal(0);

    return 0;
}