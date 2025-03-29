#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <list>
using namespace std;
class Graph
{
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int origin, int dest, bool direction)
    {
        // true single direction origin to destination
        if (direction)
        {
            this->adjList[origin].push_back(dest);
        }
        else
        {
            // false bidirectional
            this->adjList[origin].push_back(dest);
            this->adjList[dest].push_back(origin);
        }
    }
    void printAdjList(int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Key : " << i << " ->";
            for (auto e : adjList[i])
            {
                cout << e << ", ";
            }
            cout << endl;
        }
        cout << endl;
    }
};
int main()
{
    system("cls");
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.printAdjList(4);
    return 0;
}