#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <list>
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
};
int main()
{
    system("cls");
    Graph g;
    g.addEdge(0, 1, 9, 1);
    g.addEdge(0, 2, 8, 1);
    g.addEdge(1, 2, 7, 1);
    g.addEdge(2, 3, 6, 1);
    g.printAdjList(4);
    return 0;
}